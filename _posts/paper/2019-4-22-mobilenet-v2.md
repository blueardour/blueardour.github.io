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

[Goto Mobilenet v1?](https://blueardour.github.io/2019/04/17/mobilenet-v1.html)

# Code
One of the great work with pytorch framework is [here](https://github.com/tonylins/pytorch-mobilenet-v2).

# problem with mobilenet v1 and mobilenet v2's explain and solution
The depthwise-conv is easily to get zero gradient during training, so call 'degradation' problem. Mobilenet v2 gives some explain and solution.
More comparason could be found in this [discussion](https://www.zhihu.com/question/265709710/answer/298245276).

# Paper content
For activations on the CNN network, researchers think the useful information could be expressed by less data of the activation. In other word, normal activation contained redudent message, including the desired abstraction. Based on this belief, the authors of mobilenet-v2 shrink the dimension to reduce redudent to maniford of the useful information. Others also have a try before but turn out no so good result. The authors of mobilenet-v2 think this maybe caused by the non-lineaer layer. Non-linear layers are good and neccessary to sparse the information to abstract what we want, however they aslo lead to the loss of information (some of which may be important). Mobilenet-v2's solution is the linear bottleneck and revert residual structure.

## Linear Bottlenecks
The non-linear effect on activation could be show in the following figure.
![A01](/w3c/images/paper/mobilenet-v2-01.png "A01")
Non-linear could filter some information. If keep enough channel, the useful information could be still keeped after non-linear. Otherwise, the ouput might not map back.


## Inverted Residual Block
The classical residual block is:  thick-thin-thick. The reverted residual block is: thin-thick-thin. When no thick between the thin, it becomes identify block.
![A02](/w3c/images/paper/mobilenet-v2-02.png "A02")

![03](/w3c/images/paper/mobilenet-v2-03.png "A03")

They use a hyperparameter to control the thickness of the block -- the expansion rate. It's the channel multiler against the thin input activation. The paper gives some advise of the chosen of the parameter.
![10](/w3c/images/paper/mobilenet-v2-10.png "A04")

## mobilenet-v2 structure
Different from other ones:
![05](/w3c/images/paper/mobilenet-v2-05.png "A05")

Total structure configurtion:
![04](/w3c/images/paper/mobilenet-v2-04.png "A06")

## imagenet trainning
![09](/w3c/images/paper/mobilenet-v2-09.png "A07")

The performance:
![08](/w3c/images/paper/mobilenet-v2-08.png "A08")

## some trival on complexity and relu

![06](/w3c/images/paper/mobilenet-v2-06.png "A09")

![07](/w3c/images/paper/mobilenet-v2-07.png "A10")

# Blogs
The following blogs also give great explain/experiment analysis/comparason of mobilenet v1/v2.
1.[https://zhuanlan.zhihu.com/p/50045821](https://zhuanlan.zhihu.com/p/50045821)
2.[https://perper.site/2019/03/04/MobileNet-V2-%E8%AF%A6%E8%A7%A3/](https://perper.site/2019/03/04/MobileNet-V2-%E8%AF%A6%E8%A7%A3/)

[Goto Mobilenet v1?](https://blueardour.github.io/2019/04/17/mobilenet-v1.html)

