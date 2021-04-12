---
layout: post
title: Even Kernel
categories: quantization ai cv model-compression
date: 2020-07-07 02:38:59
pid: 20200707-023859
pin: 48
# you can override the settings in _config.yml here !!
---

# Introduction

Convolution with even-sized kernels and symmetric padding

[paper](https://arxiv.org/pdf/1903.08385.pdf)


Shift Problem:

![Accuracy-vs-Speed](/w3c/images/paper/Even-kernel-1.jpg)

Asymmetric padding vs symmetric padding:

![Accuracy-vs-Speed](/w3c/images/paper/Even-kernel-2.jpg)

Training loss curve:

![Accuracy-vs-Speed](/w3c/images/paper/Even-kernel-3.jpg)
