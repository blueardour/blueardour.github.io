---
layout: post
title: Image segmentation
categories: segmentation ai cv summary
date: 2019-04-30 02:50:59
pid: 20190430-025059
pin: 19
# you can override the settings in _config.yml here !!
---

# Introduction
Sementation is to parse objects in an image. Generally, the type of objects are limited and pre-known. The task requires to output the fine-grain bounding of all objects.
The task is well-studied and own strong practical value in productions. Image segmentation could be classified into instance segmentation and semantic segmentation.

Semantic segmentation only cares about the category and need not to distinguish different objects belonging to the same category. On contrast, instance segmentation need to parse the bounding for every objects. Objects belonging to the same category should also be marked different.


# Semantic Segmentation

## FCN: fully convolutional networks for semantic segmentation
1. Maybe the first one to employ full convolution network in segmentation.
2. employ pretrain parameters(alexnet, vgg, googlenet) from imagenet classification (parameter initilzation is important)
3. fuse deeper and coarse information with previous fine-grain, shadow layer
4. other tricks: deconv instead bilinear upsample, dataset imbalance, dataset augmentation, use sbd dataset

## Pspnet

## Deeplab

# Instance segmentation
## Mask RCNN


