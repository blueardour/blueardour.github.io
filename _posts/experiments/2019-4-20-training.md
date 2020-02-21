---
layout: post
title: Training History
categories: training-trick experiments quantization
date: 2019-04-20 12:38:11
pid: 20190420-123811
pin: 11
# you can override the settings in _config.yml here !!
---

# Networks Accuracy trained

Paper | Dataset | Network | Bit(A/W/G) | Paper report | My Accuracy | Comment
----- | ---- | ---------- | ------ | -------  |  ---------  
Group-net | imagenet | resnet18 | 1/1/32 | 63.x | 63.772 | without-softgate, sgd-with-decay, small-lr 
LQ-net | cifar10 | vgg-small | 32/32/32 | 93.8 | 94.21 | - 
LQ-net | cifar10 | vgg-small | 2/1/32 | 93.4 | - | - 
LQ-net | cifar10 | vgg-small | 2/2/32 | 93.5 | 94.41 | - 
LQ-net | cifar10 | vgg-small | 3/2/32 | 93.8 | - | - 
LQ-net | cifar10 | vgg-small | 3/3/32 | 93.8 | - | -
LQ-net | cifar10 | resnet20 | 32/32/32 | 92.1 | 92.86 | bacs
LQ-net | cifar10 | resnet20 | 32/32/32 | 92.1 | 92.36 | cbas,proxquant
LQ-net | cifar10 | resnet20 | 2/1/32 | 88.4 | 88.97 | bacs 
LQ-net | cifar10 | resnet20 | 2/2/32 | 90.2 | 90.16 | bacs 
LQ-net | cifar10 | resnet20 | 2/2/32 | 90.2 | 90.84 | bacs, momentum, lr=0.1, v7-1
MLQ-net | cifar10 | resnet20 | 2/2/32 | 90.2 | 90.41 | bacs, lqnet W + alqnet A
ALQ-net | cifar10 | resnet20 | 2/2/32 | 90.2 | 90.36 | bacs, v0_rand_1
LQ-net | cifar10 | resnet20 | 3/2/32 | 91.1 | 91.34 | bacs 
LQ-net | cifar10 | resnet20 | 3/3/32 | 91.6 | 92.23 | bacs 
LQ-net | cifar10 | resnet20 | 32/2/32 | 91.8 | 91.86 | bacs, _0
ALQ-net | cifar10 | resnet20 | 32/2/32 | 91.8 | 91.93 | bacs, v2-0
LQ-net | cifar10 | mobilenetv1 | 32/32/32 | - | 90.93 | cbas
LQ-net | cifar100 | resnet20 | 32/32/32 | - | 68.75 | bacs 
LQ-net | cifar100 | resnet20 | 32/2/32 | - | 67.3 | bacs 
LQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.10 | bacs, v7-0.001_v9_off_0
MLQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.55 | bacs, av0_wv0-v9_1
NLQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.88 | bacs, aoff-v0_wv0_1
NLQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.73 | bacs, aoff-v0_wv0_3
ALQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.42 | bacs, v0_1
ALQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.7 | bacs, v0_nod_1
ALQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.57 | bacs, v0_nod_2
ALQ-net | cifar100 | resnet20 | 2/2/32 | - | 63.58 | bacs, v0_rand_1
ALQ-net | cifar100 | resnet20 | 2/2/32 | - | 64.47 | bacs, v0_nod2_1
LQ-net | cifar100 | mobilenetv1 | 32/32/32 | 65.98 | 68.23 | cbas, weiaicunzai
LQ-net | imagenet | alexnet | 32/32/32 | 61.8 | 62.57 | acb, dali, server
LQ-net | imagenet | alexnet | 32/32/32 | 61.8 | 62.644 | acb, phoenix, imagenet
LQ-net | imagenet | alexnet | 32/2/32 | 60.5 | 60.418 | acb, imagenet
LQ-net | imagenet | resnet18 | 32/32/32 | 69.6 | 69.7 | epochs=100, SGDR, bacs
LQ-net | imagenet | resnet18 | 32/32/32 | 69.6 | 70.2 | epochs=120, custom-step, bacs, imagenet
LQ-net | imagenet | resnet18 | 32/32/32 | 69.6 | 70.09 | epochs=120, custom-step, bacs, dali
LQ-net | imagenet | resnet18 | 2/2/32 | 64.0 | 64.19 | archlab, epoch2=120, custom-step, imagenet
LQ-net | imagenet | resnet18 | 2/1/32 | 62.6 | ? | server
Dorefa | cifar10 | resnet20 | 32/32/32 | - | 92.86 | TTN,bacs
Dorefa | cifar10 | resnet20 | 32/1/32 | - | 90.47 | pytorch-dorefa
Dorefa | cifar10 | resnet20 | 32/2/32 | - | 91.7 | pytorch-dorefa
Dorefa | cifar10 | resnet20 | 32/1/32 | - | 90.95 | my code, bacs
Dorefa | cifar10 | resnet20 | 2/2/32 | - | 89.51 | my code, cbas, stratch
Dorefa | cifar10 | resnet20 | 2/2/32 | - | 85.06 | my code, cbas, finetune, epoch=100
Dorefa | cifar10 | resnet20 | 2/2/32 | - | 89.65 | my code, cbas, finetune, epoch=200
PACT | cifar10 | resnet20 | 2/2/32 | - | 89.36 | my code, cbas, stratch
Dorefa | cifar10 | resnet20 | 3/3/32 | - | 90.44 | my code, cbas, stratch
Dorefa | imagenet | alexnet | 32/32/32 | 61.8 | 61.83 | acb, imagenet, sgdr
Dorefa | imagenet | alexnet | 32/32/32 | 61.8 | 57.176 | acb, imagenet, custom-step
Dorefa | imagenet | alexnet | 2/1/32 | 53.4 | 56.524 | acb, imagenet, adam, stratch
Dorefa | imagenet | resnet18 | 4/1/32 | 59.2 | 65.348 | bacs, adam, 90 epochs, finetune
Dorefa | imagenet | resnet18 | 4/1/32 | 59.2 | 61.156 | bacs, sgd, 120 epochs, stratch
Dorefa | imagenet | resnet18 | 2/2/32 | - | 64.206 | bacs, sgd-4, 30 epochs, finetune
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.734 | bacs, wt-var, sgd-5, 
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 67.008 | bacs, wt-var, sgd-4, bs=256, imagenet, WD=1e-4
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.856 | bacs, wt-var, sgd-4, FP16
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.842 | bacs, wt-var, sgd-9, FP16, 40EP, n-d-s, WD=2e-5
Dorefa-TET | imagenet | resnet18 | 1/1/32 | - | 51.338 | bacs, wt-var, sgd-9, FP16, 40EP, n-d-s, WD=2e-5
Dorefa-TET | imagenet | resnet18 | 1/1/32 | - | ??.??? | bacs, wt-var, sgd-9, FP16, 40EP, n-d-s, WD=2e-5, wtet
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 65.796 | bacs, wt-non, sgd-9, FP16, 40EP, n-d-s, WD=2e-5, wtet
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.962 | bacs, wt-var, sgd-9, FP16, 40EP, n-d-s, WD=2e-5, wtet
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 63.132 | bacs, wt-var, sgd-9, bs=1024 40EP
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.788 | bacs, wt-var, sgd-9, FP16, 40EP, n-d-s, WD=1e-4
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 65.918 | bacs, wt-var, sgd-9, FP16, 40EP, n-d-s, WD=1e-4 scale5-fan 
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | diverg | bacs, wt-var, sgd-4, FP16, grad-scale:fan-scale2
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | diverg | bacs, wt-var, sgd-4, FP16, grad-scale:fan-scale1
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 63.586 | bacs, wt-var, sgd-4, FP16, grad-scale:mean-fan-scale2
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 63.078 | bacs, wt-var, sgd-4, FP16, grad-scale:mean-fan-scale1
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.032 | bacs, wt-var, sgd-8, mixup0.7, 60EP, n-d-s 
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.508 | bacs, wt-var, sgd-4, fix-arch
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.968 | bacs, wt-var, sgd-4, fix-arch, small WD
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.442 | bacs, wt-var, sgd-7, fix-arch, mixup0.7, 90EP, n-d-s
Dorefa-TET | imagenet | resnet18 | 2/2/32 | - | 66.802 | bacs, wt-var, sgd-4, fix-arch2 singleconv
Dorefa-TET | imagenet | det-r18 | 2/2/32 | - | 65.504 | wt-mean-var {1}, sgd-9, FP16 O1 wd2e-5
Dorefa-TET | imagenet | det-r34 | 2/2/32 | - | 69.858 | wt-mean-var {1}, sgd-9, FP16 O1 wd2e-5
 Fixup | imagenet | resnet18 | 32/32/32 | 68.776 | 68.956 | cbsa, mixup0.7, 120 epochs, stratch
 Fixup | imagenet | resnet18 | 32/32/32 | 68.776 | 68.776 | cbsa, no mixup, 120 epochs, stratch
 HORQ++ | imagenet | resnet18 | 32/32/32 | - | 67.902 | bacs, PReLU
 HORQ++ | imagenet | resnet18 | 32/32/32 | - | ?????? | bcas,

{1}: has no effect, as it uses the dorefa.qfn function which support var only

