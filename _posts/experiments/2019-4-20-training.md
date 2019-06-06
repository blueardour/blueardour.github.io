---
layout: post
title: Training Log
categories: training-trick
date: 2019-04-20 12:38:11
pid: 20190420-123811
pin: 11
# you can override the settings in _config.yml here !!
---

# Training script

A-task:
  pytorch-examples: imagenet-v1, sgd, no weight decay for depth-wise layer, 0.95 decay, nesterov=True, 120 epochs

B-task:
  pytorch-examples: imagenet-v2, sgd, no weight decay for depth-wise layer, 0.95 decay, nesterov=True, 120 epochs
    
C-task: 
  pytorch-examples: resnet18, sgd, no weight decay for small parameter, fix_step, 0.3 decay every 10 epochs, nesterov=True, 90 epochs

D-task:
  group-net

E-task:
  > pytorch-examples/imagenet: estimate the effect of iter_size based on resnet

Archlab:
  group-net: scale = 0.5 / 1

# tricks

## which optimizer to choose for CNN training
Here is a blog gives easy and clear explain: [optimizer的比较](https://zhuanlan.zhihu.com/p/32165402)

## how to set lr/weight_decay/momentum independently in pytorch
See the pre-parameter options section from link [https://pytorch.org/docs/stable/optim.html](https://pytorch.org/docs/stable/optim.html)

> Optimizer s also support specifying per-parameter options. To do this, instead of passing an iterable of Variable s, pass in an iterable of dict s. Each of them will define a separate parameter group, and should contain a params key, containing a list of parameters belonging to it. Other keys should match the keyword arguments accepted by the optimizers, and will be used as optimization options for this group.
> 
> NOTE
> 
> You can still pass options as keyword arguments. They will be used as defaults, in the groups that didn’t override them. This is useful when you only want to vary a single option, while keeping all others consistent between parameter groups. For example, this is very useful when one wants to specify per-layer learning rates:
> 
> optim.SGD([ {'params': model.base.parameters()},
>             {'params': model.classifier.parameters(), 'lr': 1e-3}
>           ],
>           lr=1e-2, momentum=0.9)

Also refer example from link: [https://discuss.pytorch.org/t/problem-on-different-learning-rate-and-weight-decay-in-different-layers/3619](https://discuss.pytorch.org/t/problem-on-different-learning-rate-and-weight-decay-in-different-layers/3619)

I've aslo implement the function in pytorch-examples/imagenet project.

## realize the L2/L1 norm with the loss function rather than optimazier
Refer link [https://discuss.pytorch.org/t/how-does-one-implement-weight-regularization-l1-or-l2-manually-without-optimum/7951](https://discuss.pytorch.org/t/how-does-one-implement-weight-regularization-l1-or-l2-manually-without-optimum/7951)

## Batchnorm in SR
For super-resolution problem, batch_norm is not recommended because it normalizes the intensity level across samples in each batch.

refer discussion [link](https://github.com/twtygqyy/pytorch-vdsr/issues/26)



