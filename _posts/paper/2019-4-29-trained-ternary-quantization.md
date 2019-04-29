---
layout: post
title: TRAINED TERNARY QUANTIZATION
categories: model-compression ai quantization
date: 2019-04-24 02:38:11
pid: 20190424-023811
pin: 15
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is model quantization. 

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Here summarize parts of the related papers.

# TRAINED TERNARY QUANTIZATION
# Trained Ternary Quantization
[paper link](https://arxiv.org/abs/1612.01064)
[Code](https://github.com/czhu95/ternarynet)

