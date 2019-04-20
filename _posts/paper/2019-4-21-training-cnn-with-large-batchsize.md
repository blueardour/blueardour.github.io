---
layout: post
title: Training CNN with large batchsize
categories: training-trick
date: 2019-04-21 12:38:11
pid: 20190421-123811
pin: 12
# you can override the settings in _config.yml here !!
---

# Introduction
When I come up with new ideas in CV & CNN research, I have to conduct the experiments to validate them. However, the process is timee consuming, for example, training a resnet18 on imagenet cost nearly a week on single machine. Employing more machines indeed gives a speedup, but I have no quite a lot of resource. Thus, I wonder if there is some method, such as setting up specfic hyperparameter during training to train more efficiently. Batchsize and learning rate are two of the most important factors that impact the converge speed and accuracy. 

From the view of traditional machine learning researchers, more bigger batchsize provides more less-noisy (more correct directions) gradient. However, this ruler only suits convex problem. For more CV & CNN problems, they are often non-convex, in which large batchsize may cause unstable of training. Large batchsize in CNN (for example several K), does not generate well on various problems. The gradient decent is more likely to trapped in local minivalue and misses the global minimum. Another issue for large batchsize is the parameter is updated for a low frequncy. Because, one should finish a large batchsize before updating weight to decend the gradient. This is harmful at the early stage of training. Therefore some people add a warm up step to fix it. There are also some researchers leverage dynamic batchsize, small in the beginning to update the weight quickly and large batchsize latter to obtain more accurate direction.

The learning rate should act in concert with the batchsize. Generally, when the batchsize increase n times, the learning rate should incease sqrt(n) times. (Larger batchsize indicates large learning rate, leading a faster training).

# Paper

Here I list some interesting work.

1.[On Large-Batch Training for Deep Learning: Generalization Gap and Sharp Minima](https://arxiv.org/abs/1609.04836) on ICLR2017

Abstract: The stochastic gradient descent (SGD) method and its variants are algorithms of choice for many Deep Learning tasks. These methods operate in a small-batch regime wherein a fraction of the training data, say 32-512 data points, is sampled to compute an approximation to the gradient. It has been observed in practice that when using a larger batch there is a degradation in the quality of the model, as measured by its ability to generalize. We investigate the cause for this generalization drop in the large-batch regime and present numerical evidence that supports the view that large-batch methods tend to converge to sharp minimizers of the training and testing functions - and as is well known, sharp minima lead to poorer generalization. In contrast, small-batch methods consistently converge to flat minimizers, and our experiments support a commonly held view that this is due to the inherent noise in the gradient estimation. We discuss several strategies to attempt to help large-batch methods eliminate this generalization gap.

2.[Large batch size training of neural networks with adversarial training and second-order information](https://arxiv.org/abs/1810.01021) 

Comment: I think the paper is worth to read and redo their experiment.
Abtract: The most straightforward method to accelerate Stochastic Gradient Descent (SGD) is to distribute the randomly selected batch of inputs over multiple processors. To keep the distributed processors fully utilized requires commensurately growing the batch size; however, large batch training usually leads to poor generalization. Existing solutions for large batch training either significantly degrade accuracy or require massive hyper-parameter tuning. To address this issue, we propose a novel large batch training method which combines recent results in adversarial training and second order information. We extensively evaluate our method on Cifar-10/100, SVHN, TinyImageNet, and ImageNet datasets, using multiple NNs, including residual networks as well as smaller networks such as SqueezeNext. Our new approach exceeds the performance of the existing solutions in terms of both accuracy and the number of SGD iterations (up to 1\% and 5×, respectively). We emphasize that this is achieved without any additional hyper-parameter tuning to tailor our proposed method in any of these experiments. With slight hyper-parameter tuning, our method can reduce the number of SGD iterations of ResNet18 on Cifar-10/ImageNet to 44.8× and 28.8×, respectively. We have open sourced the method including tools for computing Hessian spectrum.

3.[Train longer, generalize better: closing the generalization gap in large batch training of neural networks](https://papers.nips.cc/paper/6770-train-longer-generalize-better-closing-the-generalization-gap-in-large-batch-training-of-neural-networks.pdf)

Abtract:
We examine the initial high learning rate training phase. We
find that the weight distance from its initialization grows logarithmically with the
number of weight updates. We therefore propose a "random walk on a random
landscape" statistical model which is known to exhibit similar "ultra-slow" diffusion
behavior. Following this hypothesis we conducted experiments to show empirically
that the "generalization gap" stems from the relatively small number of updates
rather than the batch size, and can be completely eliminated by adapting the
training regime used. We further investigate different techniques to train models
in the large-batch regime and present a novel algorithm named "Ghost Batch
Normalization" which enables significant decrease in the generalization gap without
increasing the number of updates. To validate our findings we conduct several
additional experiments on MNIST, CIFAR-10, CIFAR-100 and ImageNet. Finally,
we reassess common practices and beliefs concerning training of deep models and
suggest they may not be optimal to achieve good generalization.

4.[Accurate, Large Minibatch SGD: Training ImageNet in 1 Hour](https://research.fb.com/wp-content/uploads/2017/06/imagenet1kin1h5.pdf)
comment: I heard this pare ago. They are frome facebook and the result is amazing and inspiring.
Abstract: Deep learning thrives with large neural networks and
large datasets. However, larger networks and larger
datasets result in longer training times that impede research and development progress. Distributed synchronous
SGD offers a potential solution to this problem by dividing
SGD minibatches over a pool of parallel workers. Yet to
make this scheme efficient, the per-worker workload must
be large, which implies nontrivial growth in the SGD minibatch size. In this paper, we empirically show that on the
ImageNet dataset large minibatches cause optimization difficulties, but when these are addressed the trained networks
exhibit good generalization. Specifically, we show no loss
of accuracy when training with large minibatch sizes up to
8192 images. To achieve this result, we adopt a linear scaling rule for adjusting learning rates as a function of minibatch size and develop a new warmup scheme that overcomes optimization challenges early in training. With these
simple techniques, our Caffe2-based system trains ResNet50 with a minibatch size of 8192 on 256 GPUs in one hour,
while matching small minibatch accuracy. Using commodity hardware, our implementation achieves ∼90% scaling
  efficiency when moving from 8 to 256 GPUs. This system
  enables us to train visual recognition models on internetscale data with high efficiency.

5.[Scaling SGD Batch Size to 32K for ImageNet Training](https://people.eecs.berkeley.edu/~youyang/publications/batch32k.pdf)
comment: this is similar with the third one(training longer), they also examined the learning rate.

Abtract: The most natural way to speed-up the training of large networks is to use dataparallelism on multiple GPUs. To scale Stochastic Gradient (SG) based methods
to more processors, one need to increase the batch size to make full use of the
computational power of each GPU. However, keeping the accuracy of network
with increase of batch size is not trivial. Currently, the state-of-the art method is to
increase Learning Rate (LR) proportional to the batch size, and use special learning
rate with "warm-up" policy to overcome initial optimization difficulty.
By controlling the LR during the training process, one can efficiently use largebatch in ImageNet training. For example, Batch-1024 for AlexNet and Batch-8192
for ResNet-50 are successful applications. However, for ImageNet-1k training,
  state-of-the-art AlexNet only scales the batch size to 1024 and ResNet50 only scales
  it to 8192. The reason is that we can not scale the learning rate to a large value. To
  enable large-batch training to general networks or datasets, we propose Layer-wise
  Adaptive Rate Scaling (LARS). LARS LR uses different LRs for different layers
  based on the norm of the weights (||w||) and the norm of the gradients (||∇w||).
  By using LARS algoirithm, we can scale the batch size to 32768 for ResNet50 and
  8192 for AlexNet. Large batch can make full use of the system’s computational
  power. For example, batch-4096 can achieve 3× speedup over batch-512 for
  ImageNet training by AlexNet model on a DGX-1 station (8 P100 GPUs).

6.[Don't Decay the Learning Rate, Increase the Batch Size](https://openreview.net/pdf?id=B1Yy1BxCZ)
comment: this paper (from Google Brain) is very intersting. They do not decrease the learning but increset the batch size. accpeted as a poster in ICLR2018.
Abtract: It is common practice to decay the learning rate. Here we show one can usually
obtain the same learning curve on both training and test sets by instead increasing
the batch size during training. This procedure is successful for stochastic gradient descent (SGD), SGD with momentum, Nesterov momentum, and Adam. It
reaches equivalent test accuracies after the same number of training epochs, but
with fewer parameter updates, leading to greater parallelism and shorter training
times. We can further reduce the number of parameter updates by increasing the
learning rate 
and scaling the batch size B ∝It is common practice to decay the learning rate. Here we show one can usually
obtain the same learning curve on both training and test sets by instead increasing
the batch size during training. This procedure is successful for stochastic gradient descent (SGD), SGD with momentum, Nesterov momentum, and Adam. It
reaches equivalent test accuracies after the same number of training epochs, but
with fewer parameter updates, leading to greater parallelism and shorter training
times. We can further reduce the number of parameter updates by increasing the
learning rate  Finally, one can increase the momentum coefficient m and scale B ∝ 1/(1 − m), although this tends to slightly
reduce the test accuracy. Crucially, our techniques allow us to repurpose existing
training schedules for large batch training with no hyper-parameter tuning. We
train ResNet-50 on ImageNet to 76.1% validation accuracy in under 30 minutes.

# Discussion
The problem is talked about on website frequently and many people intersted in. Here are some of threds:
1.[https://stats.stackexchange.com/questions/164876/tradeoff-batch-size-vs-number-of-iterations-to-train-a-neural-network](https://stats.stackexchange.com/questions/164876/tradeoff-batch-size-vs-number-of-iterations-to-train-a-neural-network)
2.[https://www.quora.com/Intuitively-how-does-mini-batch-size-affect-the-performance-of-stochastic-gradient-descent](https://www.quora.com/Intuitively-how-does-mini-batch-size-affect-the-performance-of-stochastic-gradient-descent)
3.[https://www.reddit.com/r/MachineLearning/comments/4bdeoy/what\_are\_the\_downsides\_to\_having\_a\_large\_batch/](https://www.reddit.com/r/MachineLearning/comments/4bdeoy/what_are_the_downsides_to_having_a_large_batch/)
4.[https://forums.fast.ai/t/tip-reduce-the-batch-size-to-generalize-your-model/20444/4](https://forums.fast.ai/t/tip-reduce-the-batch-size-to-generalize-your-model/20444/4)



