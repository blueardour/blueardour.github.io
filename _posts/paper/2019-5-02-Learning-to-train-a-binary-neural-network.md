---
layout: post
title: Learning to train a binary neural network
categories: model-compression ai quantization
date: 2019-05-02 09:08:11
pid: 20190502-090811
pin: 22
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is model quantization. 

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Here summarize one of the papers.

Other related papers could be found in [model-compression-summary](https://blueardour.github.io/2019/04/29/model-compression-summary.html)

# Learning to train a binary neural network
[paper link](https://arxiv.org/abs/1809.10463)
From HPI

# Tricks
1. add gradient clipping threshold
2. add skip connection
3. From their experience, bottleneck is harmful for binarized network and should be avoid in network structure design.
4. The forward/backward scale in XNor-net and Dorefa-net seems not useful.
5. Visualize the histogram/weight when possible

# Thinking
The gradients have a large dynamic range which is harmful for quantization. We are not better to normalize them as they might impact the converge. However, we could limited the range by clipping.


