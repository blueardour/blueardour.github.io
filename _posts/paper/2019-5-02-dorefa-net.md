---
layout: post
title: DeRefa-net Training Low Bitwidth Convolutional Neural Networks with Low Bitwidth Gradients
categories: model-compression ai quantization
date: 2019-05-02 09:38:11
pid: 20190502-093811
pin: 21
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is model quantization. 

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Here summarize one of the papers.

Other related papers could be found in [model-compression-summary](https://blueardour.github.io/2019/04/29/model-compression-summary.html)

# DeRefa-net:
[paper link](https://arxiv.org/abs/1606.06160)

# Highlight
The paper proposes a quantization method with the feature of quantize the activation/weight/gradient at the same time. They try to generalize the binarized network to efficiently trained on resource limited devices. Because they quatizate the activation/weight as well as the gradient, the framework could save computing and runtime memory.

# Quantization of weight
This paper use the following forward and backward function for quantized weight. Un-like the Xnor-net, it employs constant scale for the binrized weight (In XNor-net, the scale is calculated by the mean of abs of the weight).
![t1](/w3c/images/paper/dorafa-1.jpg "z1")

For binary weight:
![t2](/w3c/images/paper/dorafa-2.jpg "z2")

For other precision weight:
![t3](/w3c/images/paper/dorafa-3.jpg "z3")

# Quantization of activation
The quantization of activation is easy, because the dynamic range of the activation is general fixed by normalization (such as BN layer).
![t4](/w3c/images/paper/dorafa-4.jpg "z4")

# Quantization of gradient
We could not regress the range of the gradient. Thus, we could not employ the quantization function of the activation. The function is similar with the quantization function the weight but without tanH regression. The scale is calculated for each sample.
![t5](/w3c/images/paper/dorafa-5.jpg "z5")

Besides, an important trick is to add some noise into the quantization function to increase robust.
![t6](/w3c/images/paper/dorafa-5.jpg "z6")
![t7](/w3c/images/paper/dorafa-5.jpg "z7")

# Other tricks
1. do not quantize the first and last layer
2. fusion adhere layers to save runtime memory cost
3. use small learning rate(1e-4), and decrease to 1e-6.
4. use Adam optimizer.
5. try to initilize the low precision network with pre-trained full precision network.

# result
![t8](/w3c/images/paper/dorafa-8.jpg "z8")




