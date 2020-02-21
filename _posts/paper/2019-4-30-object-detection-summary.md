---
layout: post
title: Object detection Summary
categories: detection ai cv summary
date: 2019-04-30 02:30:59
pid: 20190430-023059
pin: 18
# you can override the settings in _config.yml here !!
---

# Introduction
Object detection is to detection the objects in an image. Generally, the type of objects are limited and pre-known. The task requires to output the bounding box (usually a rectangle box) of all objects.
The task is well-studied and own strong practical value in productions.

CNN based object detecion mainly consists of two stage network and one stage network. Current days, it seems the one stage network overwhelm the scenario.

# One stage detector

## SSD

## Yolo

## Retina-net(Focal loss)

## FCOS

## EfficientDet

## ScratchDet


# How to improve the detection network

1. ScratchDet The downsample in the Resnet stem is too high? Try 3x3 conv
   [Discussion](https://zhuanlan.zhihu.com/p/59498319)

2. FPN is used for multiple scale fusion.
   Try: [NAS-FPN] or [EfficientDet] or [PANet]
   refer: [Blog](https://zhuanlan.zhihu.com/p/63047557)

3. Loss function:
  try L1 norm, GIOU



