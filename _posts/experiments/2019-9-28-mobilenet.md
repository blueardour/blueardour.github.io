---
layout: post
title: MobileNet
categories: training-trick experiments quantization classification
date: 2019-09-28 12:38:11
pid: 20190717-123811
pin: 38
# you can override the settings in _config.yml here !!
---

# Networks Accuracy trained

Paper | Dataset | Network | Bit(A/W/G) | Paper report | My Accuracy | Comment
----- | ---- | ---------- | ------ | -------  |  ---------  
 -    | imagenet | v1 | 32/32/32 | - | 69.204 | cbas-0
 -    | imagenet | v1 | 32/32/32 | - | 69.800 | cbas-1
 -    | imagenet | v1 | 32/32/32 | - | 69.178 | cbas-2
 -    | imagenet | v1 | 32/32/32 | - | 65.568 | cbas-3
 -    | imagenet | v1 | 32/32/32 | - | 72.446 | cbas-4
 -    | imagenet | v1 | 32/32/32 | - | 73.164 | cbas-5
 -    | imagenet | v1 | 32/32/32 | - | 55.780 | cbas-5, group-norm=8
 -    | imagenet | v1 | 32/32/32 | - | 58.246 | cbas-5, group-norm=16
 -    | imagenet | v1 | 32/32/32 | - | 70.310 | bacs-1
 -    | imagenet | v1 | 32/32/32 | - | 67.200 | bacs-3
 -    | imagenet | v1 | 32/32/32 | - | 71.652 | bacs-4
 -    | imagenet | v2 | 32/32/32 | - | 70.416 | cbas-1
 -    | imagenet | v2 | 32/32/32 | - | 72.288 | cbas-4
 -    | imagenet | v2 | 32/32/32 | - | 71.800 | bacs-5
      | imagenet | - | - | -  |  -
 dorefa | imagenet | v1 | 4/4/32 | - | 51.940 | cbas-adam-0
 lqnet | imagenet | v1 | 2/2/32 | - | 68.094 | cbas-sgd-0 dpo wg1fg1
 lqnet | imagenet | v1 | 2/2/32 | - | 67.832 | cbas-sgd-0 dpo wg8fg8
 lqnet | imagenet | v1 | 2/2/32 | - | 59.648 | cbas-sgd-1 dpo wg1fg1 continue with pt all para same lr
 lqnet | imagenet | v1 | 2/2/32 | - | 60.670 | cbas-sgd-0 dpo wg1fg1 continue with pt custom lr
 lqnet | imagenet | v1 | 2/2/32 | - | 60.360 | cbas-sgd-0 directly wg1fg1
 lqnet | imagenet | v1 | 2/2/32 | - | 66.136 | cbas-sgd-0 pto fg8
 lqnet | imagenet | v1 | 2/2/32 | - | 66.200 | cbas-sgd-0 pto fg1
 lqnet | imagenet | v1 | 2/2/32 | - | 65.086 | cbas-sgd-1 pto fg1
      | cifar100 | - | - | -  |  -
 -    | cifar100 | v1 | 16/16/16 | - | 71.040 | cbas-0
 -    | cifar100 | v1 | 32/32/32 | - | 70.900 | cbas-0
 -    | cifar100 | v1 | 32/32/32 | - | 72.070 | cbas-1
 -    | cifar100 | v1 | 32/32/32 | - | 72.570 | cbas-2
