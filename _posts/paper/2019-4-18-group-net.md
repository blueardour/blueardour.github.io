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

 version | Arch          | pretrain FP32 | binary network | base | comment
-------- | ------------- | ------------- | -------------- | ---- | --
 origin paper | resnet18  | 69.7/89.4 | 64.2/85.6 | 4 | -
 ------------ | resnet18 | 69.7/89.4 | 64.8/85.7 | 5 | - 
 ------------ | resnet34 | 73.2/91.4 | 68.5/88.0 | 5 | -
 ------------ | resnet50 | 76.0/92.9 | 69.5/89.2 | 5 | -
 ------------ | resnet18 | 69.7/89.4 | 67.5/88.0 | 8 | -
 ------------ | resnet34 | 73.2/91.4 | 71.8/90.4 | 8 | -
 ------------ | resnet50 | 76.0/92.9 | 72.8/90.5 | 8 | -
-------- | ------------- | ------------- | -------------- | --     
-------- | ------------- | ------------- | -------------- | --     
my own | resnet18 | 68.65/87.56  | 62.298/83.392 | 5 | origin code
------ | resnet18 | 70.94/89.748 | 63.772/- | 5 | revise, sgd with decay
------ | resnet18 | 69.972/89.08 | 62.66 | 5 | revise, sgd with no decay
------ | resnet18 | 69.972/89.08 | 62.49/- | 5 | revise, adam


