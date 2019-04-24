---
layout: post
title: Mobilenet v2
categories: model-compression ai classification
date: 2019-04-24 12:38:11
pid: 20190424-123811
pin: 13
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is structure research. 

Mobilenet v1/v2 is a publication from Google. It designed a new network architecture with less parameters and operations but archive similar accuracy with famous bone networks, such as VGG, Resnet. It now has became a new baseline for network simplifaction. The main idea is to replace normal 3\*3 conv with combination of depth-wise seperate conv and point conv. Mobilenet v2 sovles the degradation problem of mobilenet v1.

There are several other similar work, includding the squeezenet, shufflenet, shiftnet, xception. Following shiftnet, there are publications from KASIT and Hikvision.

# Mobilenet -- Google
## V1
[My summary](https://blueardour.github.io/2019/04/17/mobilenet-v1.html)
[Paper Link](https://arxiv.org/abs/1704.04861)

## V2
[My summary](https://blueardour.github.io/2019/04/22/mobilenet-v2.html)
[Paper Link](https://arxiv.org/abs/1801.04381)

# Shiftnet
## Paper link
[Shift: A Zero FLOP, Zero Parameter Alternative to Spatial Convolutions](https://arxiv.org/pdf/1711.08141.pdf)
[All You Need is a Few Shifts: Designing Efficient Convolutional Neural Networks for Image Classification](https://arxiv.org/pdf/1903.05285.pdf)
[Constructing Fast Network through Deconstruction of Convolution](https://arxiv.org/pdf/1806.07370.pdf)  NIPS2019


# Blogs
The following blogs also give great explain/experiment analysis/comparason.
0.纵览轻量化卷积神经网络：SqueezeNet、MobileNet、ShuffleNet、Xception [https://zhuanlan.zhihu.com/p/32746221](https://zhuanlan.zhihu.com/p/32746221)
1.MobileNet v1 和 MobileNet v2 [https://zhuanlan.zhihu.com/p/50045821](https://zhuanlan.zhihu.com/p/50045821)
2.MobileNet V2 详解 [https://perper.site/2019/03/04/MobileNet-V2-%E8%AF%A6%E8%A7%A3/](https://perper.site/2019/03/04/MobileNet-V2-%E8%AF%A6%E8%A7%A3/)


