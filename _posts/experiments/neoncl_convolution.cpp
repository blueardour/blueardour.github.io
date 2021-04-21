/*
 * Copyright (c) 2016-2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef ARM_COMPUTE_CL /* Needed by Utils.cpp to handle OpenCL exceptions properly */
#error "This example needs to be built with -DARM_COMPUTE_CL"
#endif /* ARM_COMPUTE_CL */

#include "arm_compute/runtime/CL/CLFunctions.h"
#include "arm_compute/runtime/CL/CLScheduler.h"
#include "arm_compute/runtime/CL/CLTuner.h"

#include "arm_compute/runtime/NEON/NEFunctions.h"

#include "arm_compute/core/Types.h"
#include "utils/ImageLoader.h"
#include "utils/Utils.h"

using namespace arm_compute;
using namespace utils;

static const bool debug = false;

class LayerParameter
{
  public:
    int width, height, cin, cout, pad, stride, dilation, kernel;

    int seed;
    bool buffer_ready;
    void *input, *weight, *cpu_buffer, *gpu_buffer;

    ~LayerParameter() {
      free(input);
      free(weight);
      free(cpu_buffer);
      free(gpu_buffer);
      input = weight = cpu_buffer = gpu_buffer = NULL;
    }

    LayerParameter(int sd = 1) {
      width = height = 56;
      cin = cout = 64;
      kernel = 3;
      pad = 1;
      stride = dilation = 1;

      input = weight = cpu_buffer = gpu_buffer = NULL;
      buffer_ready = false;
      seed = sd;
    }

    int outw() { return (width  + 2*pad - kernel) / stride + 1; }
    int outh() { return (height + 2*pad - kernel) / stride + 1; }

    template <typename DType> void init(int sd = -1)
    {
      if(sd <= 0) sd = seed;
      srandom(sd);
      int len, i;
      int bs = sizeof(DType);
      DType * tmp;

      len = cin * width * height;
      input = malloc(bs * len);
      tmp = (DType *)input;
      for(i=0; i<len; i++) {
        // use tanh to bound [-1, 1]
        tmp[i] = tanh(((random() % 1000) - 500) * 0.001f);
        // override to 1 for debug
        tmp[i] = 1;
      }
      len = cin * cout * kernel * kernel;
      weight = malloc(bs * len);
      tmp = (DType *)weight;
      for(i=0; i<len; i++) {
        tmp[i] = tanh(((random() % 1000) -500) * 0.001f);
        tmp[i] = 1;
      }
      len = cout * outw() * outh();
      cpu_buffer = malloc(bs * len);
      gpu_buffer = malloc(bs * len);
      buffer_ready = true;
    }

    void save(float *buffer, int len, char *workspace) {
      std::ofstream txt;
      txt.open(workspace);
      for(int i=0; i<len; i++) {
        txt << buffer[i] << "\n";
      }
      txt.close();
    }

    void save(char *workspace) {
      char * ptr = strrchr(workspace, '/') + 1;
      int len;
      strcpy(ptr, "input.txt");
      len = cin * width * height;
      save((float *)input, len, workspace);
      strcpy(ptr, "weight.txt");
      len = cin * cout * kernel * kernel;
      save((float *)weight, len, workspace);
      strcpy(ptr, "cpu.txt");
      len = cout * outw() * outh();
      save((float *)cpu_buffer, len, workspace);
      strcpy(ptr, "gpu.txt");
      len = cout * outw() * outh();
      save((float *)gpu_buffer, len, workspace);
    }
};

static void print(ITensorInfo *info)
{
  size_t i;
  std::cout << "--> ";
  for(i=0; i<info->num_dimensions(); i++) std::cout << info->dimension(i) << ", ";
  std::cout << std::endl;
}

int test_cpu(LayerParameter *lp, DataType dtype=DataType::F32, char *workspace=NULL)
{
  std::cout << "Enter " << __FUNCTION__ << std::endl;
  // init data tensor
  Tensor* data  = new Tensor();
  const TensorShape input_shape(lp->width, lp->height, lp->cin);
  data->allocator()->init(TensorInfo(input_shape, 1, dtype));

  // init weight tensor
  Tensor* weight = new Tensor();
  const TensorShape weight_shape(lp->kernel, lp->kernel, lp->cin, lp->cout);
  weight->allocator()->init(TensorInfo(weight_shape, 1, dtype));

  // init output tensor
  Tensor* output = new Tensor();
  const TensorShape output_shape(lp->outw(), lp->outh(), lp->cout);
  output->allocator()->init(TensorInfo(output_shape, 1, dtype));

  print(data->info());
  print(weight->info());
  print(output->info());

  // init conv layer
  PadStrideInfo conv_info(lp->stride, lp->stride, lp->pad, lp->pad);

  NEConvolutionLayer *conv = new NEConvolutionLayer();
  conv->configure(data, weight, nullptr, output, conv_info);

  Status status = conv->validate(data->info(), weight->info(), nullptr, output->info(), conv_info);
  if((bool)status != true)
    std::cout << "Return Error: " << status.error_description() << std::endl;

  ConvolutionMethod method = conv->get_convolution_method(data->info(), weight->info(), output->info(), conv_info);
  if(method == arm_compute::ConvolutionMethod::GEMM)
    std::cout << "GEMM" << std::endl;
  else if(method == arm_compute::ConvolutionMethod::WINOGRAD)
    std::cout << "WINOGRAD" << std::endl;
  else if(method == arm_compute::ConvolutionMethod::DIRECT)
    std::cout << "DIRECT" << std::endl;
  else
    std::cout << "Unkown" << std::endl;

  std::cout << "cpu buffer size after configuration: " << input_shape.total_size() << ", "
    << weight_shape.total_size() << ", "
    << output_shape.total_size() << std::endl;

  // allocate and assgin value
  float * ptr;
  data->allocator()->allocate();
  ptr = (reinterpret_cast<float *>(data->buffer()));
  if(lp->buffer_ready)
    memcpy(ptr, lp->input, input_shape.total_size() *sizeof(float));
  else {
    for (size_t i = 0; i < input_shape.total_size(); i++) ptr[i] = 1.0;
  }
  for (size_t i = 0; i < input_shape.total_size() && i < 10; i++)
    std::cout << "cpu input: " << ptr[i] << std::endl;

  weight->allocator()->allocate();
  ptr = (reinterpret_cast<float *>(weight->buffer()));
  if(lp->buffer_ready)
    memcpy(ptr, lp->weight, weight_shape.total_size() *sizeof(float));
  else
    for (size_t i = 0; i < weight_shape.total_size(); i ++) ptr[i] = 1.0;

  for (size_t i = 0; i < weight_shape.total_size() && i < 10; i++)
    std::cout << "cpu weight: " << ptr[i] << std::endl;

  output->allocator()->allocate();

  print(data->info());
  print(weight->info());
  print(output->info());

  // run
  conv->run();

  ptr = reinterpret_cast<float*>(output->buffer());
  for (size_t i = 0; i < output_shape.total_size() && i < 10; i++)
    std::cout << "cpu result: " << ptr[i] << std::endl;

  // print result
  if(lp->buffer_ready) {
    memcpy(lp->cpu_buffer, ptr, output_shape.total_size() * sizeof(float));
  }
  else if(workspace != NULL) {
    std::ofstream txt;
    txt.open(workspace);
    for(size_t i=0; i<output_shape.total_size(); i++) {
      txt << ptr[i] << "\n";
    }
    txt.close();
  }

  std::cout << "Leaving " << __FUNCTION__ << std::endl;
  return 0;
}

int test_gpu(LayerParameter *lp, DataType dtype=DataType::F32, char *workspace=NULL)
{
  std::cout << "Enter " << __FUNCTION__ << std::endl;

  CLTuner cl_tuner;
  arm_compute::CLScheduler::get().default_init();

  // init data tensor
  CLTensor* data  = new CLTensor();
  const TensorShape input_shape(lp->width, lp->height, lp->cin);
  data->allocator()->init(TensorInfo(input_shape, 1, dtype));

  // init weight tensor
  CLTensor* weight = new CLTensor();
  const TensorShape weight_shape(lp->kernel, lp->kernel, lp->cin, lp->cout);
  weight->allocator()->init(TensorInfo(weight_shape, 1, dtype));

  // init output tensor
  CLTensor* output = new CLTensor();
  const TensorShape output_shape(lp->outw(), lp->outh(), lp->cout);
  output->allocator()->init(TensorInfo(output_shape, 1, dtype));

  // init conv layer
  PadStrideInfo conv_info(lp->stride, lp->stride, lp->pad, lp->pad);
  WeightsInfo weight_info = WeightsInfo();
  ActivationLayerInfo act_info = ActivationLayerInfo();

  CLConvolutionLayer* conv = new CLConvolutionLayer();
  conv->configure(data, weight, nullptr, output, conv_info);

  Status status = conv->validate(data->info(), weight->info(), nullptr, output->info(), conv_info);
  if((bool)status != true)
    std::cout << "Return Error: " << status.error_description() << std::endl;

  ConvolutionMethod method = conv->get_convolution_method(data->info(), weight->info(), output->info(),
      conv_info, weight_info, act_info, arm_compute::GPUTarget::BIFROST);
  if(method == arm_compute::ConvolutionMethod::GEMM)
    std::cout << "GEMM" << std::endl;
  else if(method == arm_compute::ConvolutionMethod::WINOGRAD)
    std::cout << "WINOGRAD" << std::endl;
  else if(method == arm_compute::ConvolutionMethod::DIRECT)
    std::cout << "DIRECT" << std::endl;
  else
    std::cout << "Unkown" << std::endl;

  std::cout << "gpu buffer size: " << input_shape.total_size() << ", "
    << weight_shape.total_size() << ", "
    << output_shape.total_size() << std::endl;

  // allocate and assgin value
  data->allocator() -> allocate();
  data->map(true);
  float * ptr;
  ptr = (reinterpret_cast<float *>(data->buffer()));
  if(lp->buffer_ready)
    memcpy(ptr, lp->input, input_shape.total_size() * sizeof(float));
  else
    for (size_t i = 0; i < input_shape.total_size(); i ++) ptr[i] = 1.0;

  for (size_t i = 0; i < input_shape.total_size() && i < 10; i++)
    std::cout << "gpu input: " << ptr[i] << std::endl;
  data->unmap();

  weight->allocator()->allocate();
  weight->map(true);
  ptr = (reinterpret_cast<float *>(weight->buffer()));
  if(lp->buffer_ready)
    memcpy(ptr, lp->weight, weight_shape.total_size() * sizeof(float));
  else
    for (size_t i = 0; i < weight_shape.total_size(); i ++) ptr[i] = 1.0;

  for (size_t i = 0; i < weight_shape.total_size() && i < 10; i++)
    std::cout << "gpu weight: " << ptr[i] << std::endl;
  weight->unmap();

  output->allocator()->allocate();

  // run
  CLScheduler::get().sync();

  conv->run();

  CLScheduler::get().sync();

  // print result
  output->map(true);
  ptr = reinterpret_cast<float*>(output->buffer());
  for (size_t i = 0; i < output_shape.total_size() && i < 10; i++)
    std::cout << "gpu result: " << ptr[i] << std::endl;

  if(lp->buffer_ready) {
    memcpy(lp->gpu_buffer, ptr, output_shape.total_size() * sizeof(float));
  }
  else if(workspace != NULL) {
    std::ofstream txt;
    txt.open(workspace);
    for(size_t i=0; i<output_shape.total_size(); i++) {
      txt << ptr[i] << "\n";
    }
    txt.close();
  }
  output->unmap();

  std::cout << "Leaving " << __FUNCTION__ << std::endl;
  return 0;
}

int main(int argc, char **argv)
{
  if(debug) printf("[debug] @ line %d: \n", __LINE__);
  char workspace[256];
  strcpy(workspace, argv[0]);

  LayerParameter lp;
  lp.width = lp.height = 40;
  lp.cin = 3;
  lp.cout = 24;
  lp.init<float>();
  test_cpu(&lp, DataType::F32, workspace);
  test_gpu(&lp, DataType::F32, workspace);
  lp.save(workspace);
  return 0;
}

