---
layout: post
title: How to train a compact binary neural network with high accuracy?
categories: model-compression ai quantization training-trick
date: 2019-05-06 09:08:12
pid: 20190506-090812
pin: 24
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification. One of them is model quantization. 

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Here summarize one of the papers.

Other related papers could be found in [model-compression-summary](https://blueardour.github.io/2019/04/29/model-compression-summary.html)

# How to train a compact binary neural network with high accuracy?
[paper link](https://pdfs.semanticscholar.org/34da/1cccce1b57372446febbab829e5676df228f.pdf)

# Tricks
1. Low learning rate is perfered, starting from 5e-4 or 1e-4. They found too big lr cause too much parameter flip during training.
![bnn2](/w3c/images/paper/how-to-train-bnn-03.png)

2. scale of weight and activation is not required, but use PRelu instead ReLU for better result
![bnn3](/w3c/images/paper/how-to-train-bnn-01.png)

3. Regularization is important. rather that L2 norm, take a bipolar regularization.
![bnn4](/w3c/images/paper/how-to-train-bnn-04.png)

4. If the last layer is also to be binarized, add a scale layer before the ouput layer
![bnn5](/w3c/images/paper/how-to-train-bnn-02.png)

5. add multiple binarization (branchs), multiple bases for better result.

Overall benefit could be see:
![bnn1](/w3c/images/paper/how-to-train-bnn-05.png)

# Thinking
The 2nd trick seems a little confilct with 'Learning to train a binary neural network'. To think more, they may improve each other's idea and and complementary to each other.



