---
layout: post
title: Training Log
categories: model-compression ai
date: 2019-04-20 12:38:11
pid: 20190420-123811
pin: 11
# you can override the settings in _config.yml here !!
---

# Training script type

A-task:
  group-net:
  mobielnet-v1: v1-base3-pretrain
  
B-task:
  group-net:
    mobilenet-v2 pretrain base1
    
C-task: 
  pytorch-example/imagenet:
  phoenix: estimate the effect of iter_size based on resnet
  archlab: same function but based on mobilenetv2

D-task:
  group-net:
    do the resnet18 experiments again
