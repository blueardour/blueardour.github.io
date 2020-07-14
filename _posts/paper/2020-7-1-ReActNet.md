---
layout: post
title: ReActNet
categories: quantization ai cv summary bnn model-compression
date: 2020-07-01 02:38:59
pid: 20200701-023859
pin: 45
# you can override the settings in _config.yml here !!
---

# ReActNet

Towards Precise Binary Neural Network with Generalized Activation Functions

This paper brings up a BNN quantization work with astonishingly high performance (Top-1: 69.4 for TypeA and 71.4 for TypeC).

![Accuracy-vs-Speed](/w3c/images/paper/ReActNet-1.jpg)


The main contribution is the structure revision:

![Accuracy-vs-Speed](/w3c/images/paper/ReActNet-2.jpg)

They downsample the resolution in the first conv3x3 by avgpool and adjust the channel in the next conv1x1. High precision skip connection without convolution is possible by the revision.

The main result table:

![Accuracy-vs-Speed](/w3c/images/paper/ReActNet-3.jpg)

Visionilization:

![Accuracy-vs-Speed](/w3c/images/paper/ReActNet-4.jpg)

I'm not agree with the explain for the figure. For the (a) sugfigure, there is no guarantee for the slope to be positive. Their explaination is non-sense from my experience.

![Accuracy-vs-Speed](/w3c/images/paper/ReActNet-5.jpg)

This figure also is not convincing. I cannot see clear evidence of superior of either one versus another based on the distribution. The \alpha has a similar function with BatchNorm. RPReLU seems just a trick and no theorical analysis. 



