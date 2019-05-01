---
layout: post
title: Relaxed Quantization for Discretized Neural Networks 
categories: model-compression ai quantization
date: 2019-04-30 09:38:11
pid: 20190430-093811
pin: 18
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is model quantization. 

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Here summarize one of the papers.

Other related papers could be found in [model-compression-summary](https://blueardour.github.io/2019/04/29/model-compression-summary.html)

# Relaxed Quantization for Discretized Neural Networks 
[paper link](https://arxiv.org/abs/1810.01875)
[Comment by reviewer](https://openreview.net/forum?id=HkxjYoCqKX)

# Highlight
I prefer this paper very much. It's both practial and sound in theory. In one sentence, it solve the non-derivative (non-differentiability) issue during quantization by employing probabilistic model. Early published papers abou the stochastic rounding deployment in low precision training could also be treated as a special case of the proposed approach.

# Method
1. The following figure gives a general quantization procedure. The problem of it is information is lost and non-invertible. It is not easy to optimize the network with gradient descent.

2. vocabulary choose. The paper gives good explain.

3. 

