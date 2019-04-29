---
layout: post
title: Trained Ternary Quantization
categories: model-compression ai quantization
date: 2019-04-29 02:38:11
pid: 20190429-023811
pin: 15
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is model quantization. 

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Here summarize one of the papers.

Other related papers could be found in [model-compression-summary](https://blueardour.github.io/2019/04/29/model-compression-summary.html)

# Trained Ternary Quantization
[paper link](https://arxiv.org/abs/1612.01064)
[Code](https://github.com/czhu95/ternarynet)
[Comment by reviewer in the ICLR](https://openreview.net/forum?id=S1_pAu9xl)
Tsinghua University && Stanford University

## Ternary assignment
means how to obtain quantization value from the FP32 weight

## Ternary value
how to choose -1, 0, +1 dynamically during the training

# Highlight
From the paper:
> We highlight our trained quantization method that can learn both ternary values and ternary assignment.

1. The paper only quantize the weight and keep the activation in full precision.
2. The main differece from other ternary quantization is the quantization value has scale. To be more detail, it quantize value to [-Wll, 0, Wp], rather than [-1, 0, +1]. This increase certain degree of capbility.
3. symmetric quantization assignment and asymmetric quantization value

# Method
Overall flow is shown in following figure.
![t1](/w3c/images/paper/trained-ternary-1.jpg "z1")

1. First scale the weight into [-1, 1]. (this maybe squeeze many small value to zero if the max value of the weight is big)
2. quantization assign hyperparameter <delta>.
![t2](/w3c/images/paper/trained-ternary-2.jpg "z2")

The paper has two strategies. One is multiple a scale on the max absolute value of the weight, the other is keep the sparsity of the all layer to be a constant during training. They choose the former one in CIFAR dataset and the later one in the Imagenet dataset.
![t4](/w3c/images/paper/trained-ternary-4.jpg "z4")

3. Wp, Wl is trainable parameter, updated by gradient during training.
![t3](/w3c/images/paper/trained-ternary-3.jpg "z3")

# Experiment

The following figure shows the Wp and Wl change during the training.
![t6](/w3c/images/paper/trained-ternary-6.jpg "z6") 
It seems that the Wl and Wp is very close to each other. Thus the paper is no value? Their conclusion may be wrong.

Why they put this figure in the paper, it is no sense with the topic.
![t5](/w3c/images/paper/trained-ternary-5.jpg "z5") 


