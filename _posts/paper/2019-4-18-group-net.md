---
layout: post
title: Structured Binary Neural Networks for Accurate Image Classification and Semantic Segmentation
categories: model-compression ai
date: 2019-04-18 12:38:11
pid: 20190418-123811
pin: 10
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is network quantization. The paper introduced today is one of the state-of-the-art one. It provided a general method for making a network into binary network. It is binary for both activation and weights. WOW! So exciting!

# Practice

## Cls on imagenet 2012 (top1/top5 accuracy)

 Base5   | pretrain FP32 | binary network |
-------- | ------------- | -------------- |          
resnet18 | 68.652/87.56  | 62.298/83.392  |
         | 69.7/89.4     |  64.8/ 85.7    |
-------- | ------------- | -------------- |         
