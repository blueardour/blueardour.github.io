---
layout: post
title: Mobilenet v2
categories: model-compression ai
date: 2019-04-22 12:38:11
pid: 20190422-123811
pin: 12
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is structure research. 

Mobilenet v1/v2 is a publication from Google. It designed a new network architecture with less parameters and operations but archive similar accuracy with famous bone networks, such as VGG, Resnet. It now has became a new baseline for network simplifaction. The main idea is to replace normal 3\*3 conv with combination of depth-wise seperate conv and point conv. Mobilenet v2 sovles the degradation problem of mobilenet v1.

# Mobilenet v2
[Paper Link](https://arxiv.org/abs/1801.04381)

[Mobilenet v1](https://blueardour.github.io/2019/04/17/mobilenet-v1.html)

One of the great work with pytorch framework is [here](https://github.com/tonylins/pytorch-mobilenet-v2).

# problem with mobilenet v1 and mobilenet v2's explain and solution
The depthwise-conv is easily to get zero gradient during training, so call 'degradation' problem. Mobilenet v2 gives some explain and solution.
More comparason could be found in this [discussion](https://www.zhihu.com/question/265709710/answer/298245276).

# Blogs
The following blogs also give great explain/experiment analysis/comparason of mobilenet v1/v2.
1.[https://zhuanlan.zhihu.com/p/50045821](https://zhuanlan.zhihu.com/p/50045821)
2.[https://perper.site/2019/03/04/MobileNet-V2-%E8%AF%A6%E8%A7%A3/](https://perper.site/2019/03/04/MobileNet-V2-%E8%AF%A6%E8%A7%A3/)

[Mobilenet v1](https://blueardour.github.io/2019/04/17/mobilenet-v1.html)
