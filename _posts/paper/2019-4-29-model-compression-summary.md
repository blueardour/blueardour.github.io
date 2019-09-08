---
layout: post
title: Model Compression Summary
categories: model-compression ai quantization summary
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

## Result Summary

Paper | Base | Activation | Weight | Gradient | First Layer | Last Layer | Model Size | Scenario | Dataset | Network | Accuracy | Comment
----- | ---- | ---------- | ------ | -------  |  ---------  | ---------- | ---------  | -------  | ------- | -------- | ------- |  -----  
Trained Ternary Quantization | - | 32 | 1 | 32 | N | N | - | cls | cifar10 | reset20 | 91.13% | asymmetric scale
Trained Ternary Quantization | - | 32 | 1 | 32 | N | N | - | cls | cifar10 | reset32 | 92.37% | drop 0.04
Trained Ternary Quantization | - | 32 | 1 | 32 | N | N | - | cls | cifar10 | reset44 | 92.98% | drop 0.16
Trained Ternary Quantization | - | 32 | 1 | 32 | N | N | - | cls | cifar10 | reset56 | 93.56% | drop 0.36
Trained Ternary Quantization | - | 32 | 1 | 32 | N | N | - | cls | imagenet | alexnet | 57.5%/79.7% | fp: 57.2%/80.3%
Trained Ternary Quantization | - | 32 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 66.6%/87.2% | fp: 69.6%/89.2%
BC | - | 32 | 1 | - | N | N | - | cls | mnist | - | - | same team with BN/BNN
BC | - | 32 | 1 | - | N | N | - | cls | SVHN | - | - | same team with BN/BNN
BC | - | 32 | 1 | - | N | N | - | cls | cifar-10 | - | - | same team with BN/BNN
BNN | - | 1 | 1 | - | N | N | - | cls | cifar-10 | - | - | shift BN & pre-BN
BNN | - | 1 | 1 | - | N | N | - | cls | SVHN | - | - | NIPS2016
BNN | - | 32 | 1 | - | N | N | - | cls | imagenet | alexnet | 35.4/61.0 | seems multi revision
BNN | - | 1 | 1 | - | N | N | - | cls | imagenet | alexnet | 27.9/50.42 | seems multi revision
XNor-net(BWN) | - | 32 | 1 | 32 | N | N | - | cls | cifar-10 | same with BC | 90.12 | -
XNor-net(BWN) | - | 32 | 1 | 32 | N | N | - | cls | cifar-10 | same with BNN | 89.83 | -
XNor-net(BWN) | - | 32 | 1 | - | N | N | - | cls | imagenet | alexnet | 56.8/79.4 | -
XNor-net(BWN) | - | 32 | 1 | - | N | N | - | cls | imagenet | resnet18 | 60.8/83.0 | -
XNor-net(BWN) | - | 32 | 1 | - | N | N | - | cls | imagenet | googlenet | 65.5/86.1 | -
XNor-net | - | 1 | 1 | 32 | N | N | - | cls | imagenet | Alexnet | 44.2/69.2 | -
XNor-net | - | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 51.2/73.2 | -
XNor-net | - | 1 | 1 | 32 | N | N | - | cls | imagenet | Googlenet | - | -
How-train-bnn | - | 2 | 1 | - | N | Y | 232MB -> 7.43MB | cls | imagenet | Alexnet | 46.6/71.1 | adam, lr: 1e-4 
How-train-bnn | - | 2 | 1 | - | N | Y | 29MB -> 1.23MB | cls | imagenet | NIN-net | 51.4/75.6 | pre-BN ?
Dorefa-net | - | 1/2/3/4/8 | 1/2/8 | 2/4/8/32 | N | N | - | cls | SVHN | * | * | better init with FP32 pretrained
Dorefa-net | - | 1/2/3/4/8 | 1/8 | 6/8/32 | N | N | - | cls | imagenet | alexnet | * | better init with FP32 pretrained
Dorefa-net | - | 1/2/3/4/8 | 1/8 | 6/8/32 | N | N | - | cls | imagenet | alexnet | * | better init with FP32 pretrained
Dorefa-net | - | 2 | 1 | 4 | Y | N | - | cls | SVHN | * | * | -
Dorefa-net | - | 2 | 1 | 4 | N | Y | - | cls | SVHN | * | * | -
Dorefa-net | - | 2 | 1 | 4 | Y | Y | - | cls | SVHN | * | * | -
Relax Quant | - | 2 | 2 | - | N | N | - | cls | MNIST/Cifar10 | - | * | -
Relax Quant | - | 4 | 4 | - | N | N | - | cls | MNIST/Cifar10 | - | * | -
Relax Quant | - | 8 | 8 | - | N | N | - | cls | MNIST/Cifar10 | - | * | -
Relax Quant | - | 4/5/6/8 | 4/5/6/8 | - | N | N | - | cls | imagenet | resnet18/mobilenet | * | appendix
HPI | - | 1 | 1 | - | N | N | 202KB vs 4.4MB | cls | MNIST | LeNet | 99.3 | -
HPI | - | 1 | 1 | - | N | N | 1.9MB vs 51MB | cls | Cifar-10 | DenseNet21 | 87.1 | -
HPI | - | 1 | 1 | - | N | N | - | cls | imagenet | alexnet/InceptionBN | * | -
HPI | - | 1 | 1 | - | N | N | - | cls | imagenet | resnet18 | 42.0/66.2 | -
HPI | - | 1 | 1 | - | N | N | - | cls | imagenet | resnet26/34/68 | * | -
HPI | - | 1 | 1 | - | N | N | * | cls | imagenet | densenet21/45 | * | -
ABC-net | A1/W5 | 32 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 68.3/87.9 | -
ABC-net | A1/W(3/2/1) | 32 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | * | -
ABC-net | A5/W5 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 65.0/85.9 | -
ABC-net | A3/W5 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 62.5/84.2 | -
ABC-net | A1/W5 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 54.1/78.1 | -
ABC-net | A5/W3 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 63.1/84.8 | -
ABC-net | A3/W3 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 61.0/83.2 | -
ABC-net | A1/W3 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 49.1/73.8 | -
ABC-net | A1/W1 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 42.7/67.6 | -
ABC-net | A(1/3/5)/W(1/3/5) | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet34/50 | * | -
Bi-Real net | - | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18/34 | * | -
Group-net | 8 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet50 | 72.8/90.5 | -
Group-net | 5 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet50 | 69.5/89.2 | -
Group-net | 8 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet34 | 71.8/90.4 | more complexity
Group-net | 5 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet34 | 68.5/88.0 | more complexity
Group-net | 8 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 67.5/88.0 | change structure
Group-net | 5 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 64.8/85.7 | change structure
Group-net | 4 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 64.2/85.6 | -
Group-net | 3 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 62.5/84.2 | -
Group-net | 1 | 1 | 1 | 32 | N | N | - | cls | imagenet | resnet18 | 55.6/78.6 | -
Group-net | 5 | 1 | 1 | 32 | N | N | - | seg | VOC2012 | resnet18/fcn-16s | 67.7 | -
Group-net | 5 | 1 | 1 | 32 | N | N | - | seg | VOC2012 | resnet18/fcn-32s | 65.1 | -
Group-net | 1/3/5 | 2/4/32 | 1 | 32 | N | N | - | cls | imagenet | resnet18/50/Alexnet | * | in appendix

Generally, '-' means uknown or unavailable. '*' indicates result exists in the paper, however too much of them to fit in the page, so look up the paper when needed.

## Efficient Super Resolution Using Binarized Neural Network
[paper link](https://arxiv.org/abs/1812.06378)
ECCV 2016

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

## ABC-nets: Towards Accurate Binary Convolutional Neural Network
[paper link](https://arxiv.org/abs/1711.11294)
[Tensorflow impl](https://github.com/layog/Accurate-Binary-Convolution-Network)

## Training Competitive Binary Neural Networks from Scratch
[paper link](https://arxiv.org/pdf/1812.01965.pdf)

## How to Train a Compact Binary Neural Network with High Accuracy?
[paper link](https://pdfs.semanticscholar.org/34da/1cccce1b57372446febbab829e5676df228f.pdf) AAAI-17

## Incremental Network Quantization: Towards Lossless CNNs with Low-Precision Weights
ICLR 2017
[paper link](https://arxiv.org/abs/1702.03044)

## Binarized Neural Networks: Training Deep Neural Networks with Weights and Activations Constrained to +1 or -1
NIPS 2016
[paper link](https://arxiv.org/abs/1602.02505)
describe the deterministic and stochastic binarization. The former is as following:
![bnn1](/w3c/images/paper/bnn-02.png "bnn1")

stochastic one is:
![bnn2](/w3c/images/paper/bnn-01.png "bnn2")

modify the BN to shift batch norm
![bnn2](/w3c/images/paper/bnn-02.png "bnn2")

has power consumption data
![bnn4](/w3c/images/paper/bnn-04.png "bnn4")

develop code on real platform and get 7x times speedup

## LQ-nets: Learned quantization for highly accurate and compact deep neural networks

## Others
1. BinaryConnect
2. BinaryNets

### Towards the Limit of Network Quantization

### The ZipML Framework for Training Models with End-to-End Low Precision: The Cans, the Cannots, and a Little Bit of Deep Learning
