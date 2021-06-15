---
layout: post
title: Compressing 1D Time-Channel Separable Convolutions using Sparse Random Ternary Matrices
categories: quantization ai cv model-compression 
date: 2021-04-18 02:38:59
pid: 20210418-023859
pin: 50
# you can override the settings in _config.yml here !!
---

# Introduction

Compressing 1D Time-Channel Separable Convolutions using Sparse Random Ternary Matrices

[paper](https://arxiv.org/pdf/2103.17142.pdf)

Replace some 1x1 convolution with Sparse Random Ternary Matrices

Based on observation that 

![Accuracy-vs-Speed](/w3c/images/paper/Sparse-Random-Ternary-Matrices-1.png)

force some weight to random sparse matrices:

![Accuracy-vs-Speed](/w3c/images/paper/Sparse-Random-Ternary-Matrices-2.png)

Good summary on related work
