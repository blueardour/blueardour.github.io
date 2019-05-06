---
layout: post
title: Model Compression Summary
categories: model-compression ai quantization
date: 2019-04-29 02:38:59
pid: 20190429-023859
pin: 16
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification.

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Following summarize parts of the related papers.

Pruning is to delete certain links in the network. Sometimes the chosen links are random selected (unstructured pruning). Sometimes fixed pattern links are chosen (structured pruning), such as channel pruning.

Knowledge distill is another kind of model compression method. It employs a redudent network to train a smaller network. The former is a teacher while the latter as a student. It could combine with beforementioned quantization and pruning. For example, knowlege distill is used for obtain a low precision network with a full precision network as a teacher.

# Quantization

# Result Summary

## XNOR-net
[paper link](https://arxiv.org/abs/1603.05279)
[Code](https://github.com/allenai/XNOR-Net)
ECCV 2016

## Group-net
[paper link](https://arxiv.org/abs/1811.10413)

## Trained Ternary Quantization
[paper link](https://arxiv.org/abs/1612.01064)
[Code](https://github.com/czhu95/ternarynet)

## PACT: PARAMETERIZED CLIPPING ACTIVATION FOR QUANTIZED NEURAL NETWORKS
[paper link](https://arxiv.org/pdf/1805.06085.pdf)

## RELAXED QUANTIZATION FOR DISCRETIZED NEURAL NETWORKS
[paper link](https://arxiv.org/abs/1810.01875)
[comment from reviews](https://openreview.net/forum?id=HkxjYoCqKX)

## DoReFa-Net: Training Low Bitwidth Convolutional Neural Networks with Low Bitwidth Gradients
[paper link](https://arxiv.org/pdf/1606.06160)

## Deep Learning with Low Precision by Half-wave Gaussian Quantization
[paper link](http://www.svcl.ucsd.edu/publications/conference/2017/cvpr/hwgq.pdf) CVPR-2017

## Learning to Train a Binary Neural Network
[paper link](https://arxiv.org/pdf/1809.10463.pdf)

## Training Competitive Binary Neural Networks from Scratch
[paper link](https://arxiv.org/pdf/1812.01965.pdf)

## How to Train a Compact Binary Neural Network with High Accuracy?
[paper link](https://pdfs.semanticscholar.org/34da/1cccce1b57372446febbab829e5676df228f.pdf) AAAI-17

## Incremental Network Quantization: Towards Lossless CNNs with Low-Precision Weights
ICLR 2017
[paper link](https://arxiv.org/abs/1702.03044)

## Binarized Neural Networks
NIPS 2016
[paper link](https://arxiv.org/abs/1602.02505)

# Towards the Limit of Network Quantization

# The ZipML Framework for Training Models with End-to-End Low Precision: The Cans, the Cannots, and a Little Bit of Deep Learning
