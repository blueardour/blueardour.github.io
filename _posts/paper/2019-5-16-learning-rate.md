---
layout: post
title: Learning Rate in CNN
categories: training-trick optimization
date: 2019-05-16 12:38:11
pid: 20190516-123811
pin: 26
# you can override the settings in _config.yml here !!
---

# Introduction
When I come up with new ideas in CV & CNN research, I have to conduct the experiments to validate them. However, the process is timee consuming, for example, training a resnet18 on imagenet cost nearly a week on single machine. Employing more machines indeed gives a speedup, but I have no quite a lot of resource. Thus, I wonder if there is some method, such as setting up specfic hyperparameter during training to train more efficiently. Batchsize and learning rate are two of the most important factors that impact the converge speed and accuracy. 

From the view of traditional machine learning researchers, more bigger batchsize provides more less-noisy (more correct directions) gradient. However, this ruler only suits convex problem. For more CV & CNN problems, they are often non-convex, in which large batchsize may cause unstable of training. Large batchsize in CNN (for example several K), does not generate well on various problems. The gradient decent is more likely to trapped in local minivalue and misses the global minimum. Another issue for large batchsize is the parameter is updated for a low frequncy. Because, one should finish a large batchsize before updating weight to decend the gradient. This is harmful at the early stage of training. Therefore some people add a warm up step to fix it. There are also some researchers leverage dynamic batchsize, small in the beginning to update the weight quickly and large batchsize latter to obtain more accurate direction.

The learning rate should act in concert with the batchsize. Generally, when the batchsize increase n times, the learning rate should incease sqrt(n) times. (Larger batchsize indicates large learning rate, leading a faster training).

# Paper

Here I list some interesting work.

1.[SGDR: Stochastic Gradient Descent with Warm Restarts](https://arxiv.org/abs/1608.03983) on ICLR2017
Restart techniques are common in gradient-free optimization to deal with multimodal functions. Partial warm restarts are also gaining popularity in gradient-based optimization to improve the rate of convergence in accelerated gradient schemes to deal with ill-conditioned functions. In this paper, we propose a simple warm restart technique for stochastic gradient descent to improve its anytime performance when training deep neural networks. We empirically study its performance on the CIFAR-10 and CIFAR-100 datasets, where we demonstrate new state-of-the-art results at 3.14% and 16.21%, respectively. We also demonstrate its advantages on a dataset of EEG recordings and on a downsampled version of the ImageNet dataset. Our source code is available at this [https URL](https://github.com/loshchil/SGDR)

Comment:
The origin paper only test the proposed method on Cifar10/100. Some followers test on imagenet, and somebody show it is indeed efficitive. Refer [here](https://github.com/tonylins/pytorch-mobilenet-v2/issues/1#issuecomment-491647024) to show to how reduce epochs from 300 to 150 of mobilenet-v2 on imagenet.


The problem is talked about on website frequently and many people intersted in. Here are some of threads:
1. [Improving the way we work with learning rate](https://techburst.io/improving-the-way-we-work-with-learning-rate-5e99554f163b)



