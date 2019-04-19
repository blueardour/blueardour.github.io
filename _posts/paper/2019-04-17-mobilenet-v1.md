---
layout: post
title: Mobilenet v1
categories: model-compression ai
date: 2019-04-17 12:38:11
pid: 20190417-123811
pin: 9
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is structure research. 

Mobilenet v1 is a publication from Google. It designed a new network architecture with less parameters and operations but archive similar accuracy with famous bone networks, such as VGG, Resnet. It now has became a new baseline for network simplifaction. The main idea is to replace normal 3\*3 conv with combination of depth-wise seperate conv and point conv.

# Mobilenet v1 [Paper Link](https://arxiv.org/abs/1704.04861)

The network architecture change:
![structure](/w3c/images/paper/mobilenet-v1-structure.png "structure")

The illustration of the depth-wise seperate conv and point-wise conv:
![dp-conv](/w3c/images/paper/mobilenet-v1-dp.png "conv layer")

And the complexity reducation by the new desinged structure:
![Complexity](/w3c/images/paper/mobilenet-v1-complexity.png "complexity")

The overall network structure of mobilenet v1:
![overall strucure](/w3c/images/paper/mobilenet-v1-2.png "overall strucure")

There are two hyperparameters to adjust fine-grain complexity. The alpha to adjust the channel width and the pie to adjust the resolution. The complexity is square related with these two hyperparameters.
![complexity hyperparamter](/w3c/images/paper/mobilenet-v1-1.png "hyperparamter")

Performance on Imagenet2012:
![performance](/w3c/images/paper/mobilenet-v1-3.png "performance")


