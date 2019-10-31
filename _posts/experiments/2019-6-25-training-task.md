---
layout: post
title: Training Log
categories: training-trick experiments quantization
date: 2019-06-25 12:38:11
pid: 20190625-123811
pin: 100
# you can override the settings in _config.yml here !!
---

# Current Task
1. archlab:
   2019.9.29 11:24 
   #0,1: 6672/0.32/120 resnet34 custom-step alqnet 3bit (expect 2019.10.12) (paused)
   #2 volta: bireal34 cbsa fp 120*5004*0.4 = 2.8d(on 2019.10.09 3:20pm) (done) 
   #1 volta: bireal34 bireal   cbsa fp 120*10009*0.50 = 7d (expect 2019.10.30) (done)
   #1 volta: bireal34 popcount cbsa fp 120*10009*0.48 = 7d (expect 2019.10.30) (done)
   #1 volta: bireal34 bireal   cbsa fp 120*10009*0.52 = 4.5d s=0.625
   #1 volta: bireal34 bireal   cbsa fp 120*10009*0.57 = 8.0d s=0.625
   
2. server:
   #1 volta: bireal18 cbsa fp  8007 * 0.22 * 120 (done)
   #1 volta: bireal18 cbsa ter bireal (done)
   #1 volta: resnet34 bacs ter sgd-1 10009 * 0.33 * 120 (done)
   #1 volta: resnet18 bacs ter bireal  (done)
   #1 volta: resnet18 bacs ter popcount s=0.25 (done)
   #1 volta: resnet34 bacs ter bireal (done)
   #1 volta: resnet18 bacs ter popcount s=0.618 (done)
   #1 volta: resnet18 bacs fp group-net group-norm=2 (done)
   #1 volta: resnet18 bacs ter popcount s=0.5 stratch (done)
   #1 volta: mobilenet v1 bacs ter popcount depth-skip s=0.5
   #1 volta: resnet18 bacs ter popcount s=0.625 (done)
   #1 volta: resnet34 bacs ter bireal s=0.625 

3. centos:
   #1 volta: resnet18 bacs fp group-net group-norm=4
   #1 volta: resnet18 bacs fp group-net group-norm=8 (stopped) (resumed from dali)

4. anton:
   #1 volta: bireal18 cbsa fp  8007 * 0.22 * 120 =  (done)
   #1 volta: resnet18 bacs 2bit alqnet quant-group: -8 (expect: 10.17) (done)
   #1 volta: resnet18 bacs ter popcount s=0.75(done)
   #1 volta: resnet18 bacs ter popcount s=0.50(done)
   #1 volta: resnet18 bacs ter popcount s=0.5 finetune wt-group=1 (done)
   #1 volta: resnet18 bacs ter bireal s=0.625

5. level4:
   #1 volta: bireal18 cbsa ter popcount (done)
   #1 volta: mobilenet v1 bacs fp depth-skip (13345 * 0.39 * 120 = 7.3d) (done)
   #1 volta: resnet18 bacs ter popcount s=0.5 stratch wt-group=1 (done)
   #1 volta: bireal18 cbsa ter bireal s=0.625

6. phoenix: 
   #2 volta: mobilenet v2 bacs fp (done)
   #2 volta: mobilenet v1 cbas 2bit (stopped for bad performance)
   #1 volta: mobilenet v1 bacs 2bit alqnet (stopped for bad performance)
   #1 volta: resnet18 bacs 2bit alqnet quant-group: -64 (paused as disk too slow, decide to cancel task)
   #1 volta: resnet18 bacs 2bit alqnet quant-group: -1 (stopped, as result is Nan) (Nan is not out of expection, as only ks*ks data participate the quantization)
   #2 volta: resnet34 cbsa fp (paused as gpu too slow) (task is re-submitted on archlab)

   cp:
   #2 volta: resnet50 bacs ter popcount s=0.5 finetune

   bohan:

   liangyi:
   #1 volta: mobilenet v1 cbas fp depth-skip (done)
   #2 volta: resnet34 bacs ter popcount s=0.625 (5005 * 0.35 * 120) (done)
   #2 volta: resnet50 bacs ter popcount s=0.625 finetune

# Training Speed Test
torch.utils.data.dataloader.DataLoader and i7-7800x + 2080ti*2:
train 0/5005, loss:7.037(7.037), batch time:11.96(11.96), data load time: 3.95(3.95)
train 20/5005, loss:6.965(7.001), batch time:0.21(0.77), data load time: 0.00(0.19)
train 40/5005, loss:6.929(6.970), batch time:0.21(0.52), data load time: 0.00(0.12)
train 60/5005, loss:6.901(6.951), batch time:0.21(0.49), data load time: 0.00(0.15)
train 80/5005, loss:6.859(6.938), batch time:2.05(0.49), data load time: 1.82(0.18)
train 100/5005, loss:6.863(6.926), batch time:0.22(0.45), data load time: 0.00(0.16)
train 120/5005, loss:6.864(6.914), batch time:0.21(0.45), data load time: 0.00(0.17)

torch.utils.data.dataloader.DataLoader and i7-7800x + 2080ti*1:
[epoch 0]: lr 1.000000e-02
train 0/5005, loss:7.038(7.038), batch time:6.70(6.70), data load time: 3.87(3.87)
train 20/5005, loss:6.979(6.999), batch time:0.29(0.61), data load time: 0.00(0.18)
train 40/5005, loss:6.929(6.970), batch time:0.30(0.46), data load time: 0.01(0.10)
train 60/5005, loss:6.882(6.951), batch time:1.36(0.45), data load time: 1.04(0.10)
train 80/5005, loss:6.880(6.939), batch time:0.31(0.42), data load time: 0.00(0.09)
train 100/5005, loss:6.875(6.929), batch time:0.29(0.42), data load time: 0.00(0.09)
train 120/5005, loss:6.862(6.917), batch time:1.85(0.42), data load time: 1.55(0.10)
train 140/5005, loss:6.818(6.904), batch time:0.33(0.42), data load time: 0.00(0.09)
train 160/5005, loss:6.724(6.889), batch time:0.30(0.41), data load time: 0.00(0.09)
train 180/5005, loss:6.814(6.877), batch time:1.28(0.41), data load time: 0.98(0.09)
train 200/5005, loss:6.786(6.863), batch time:0.31(0.40), data load time: 0.01(0.08)
train 220/5005, loss:6.690(6.849), batch time:0.31(0.40), data load time: 0.00(0.09)
train 240/5005, loss:6.693(6.834), batch time:1.83(0.41), data load time: 1.53(0.09)
train 260/5005, loss:6.622(6.821), batch time:0.31(0.40), data load time: 0.00(0.09)


dali and i7-7800x + 2080ti*1 (no display card):
train 0/1281167, loss:6.971(6.971), batch time:1.53(1.53), data load time: 0.00(0.00)
train 20/1281167, loss:7.003(6.990), batch time:0.32(0.37), data load time: 0.02(0.01)
train 40/1281167, loss:6.924(6.965), batch time:0.31(0.34), data load time: 0.01(0.02)
train 60/1281167, loss:6.909(6.948), batch time:0.31(0.33), data load time: 0.02(0.02)
train 80/1281167, loss:6.863(6.932), batch time:0.31(0.32), data load time: 0.01(0.02)
train 100/1281167, loss:6.847(6.919), batch time:0.32(0.32), data load time: 0.03(0.02)
train 120/1281167, loss:6.856(6.906), batch time:0.31(0.32), data load time: 0.02(0.02)
train 140/1281167, loss:6.827(6.892), batch time:0.30(0.32), data load time: 0.01(0.02)
train 160/1281167, loss:6.717(6.876), batch time:0.31(0.31), data load time: 0.02(0.02)
train 180/1281167, loss:6.742(6.862), batch time:0.31(0.31), data load time: 0.02(0.02)
train 200/1281167, loss:6.687(6.847), batch time:0.32(0.31), data load time: 0.02(0.02)
train 220/1281167, loss:6.600(6.830), batch time:0.31(0.31), data load time: 0.02(0.02)
train 240/1281167, loss:6.505(6.814), batch time:0.31(0.31), data load time: 0.02(0.02)

dali and i7-7800x + 2080ti*1 (display card):
[epoch 0]: lr 1.000000e-02
train 0/5004, loss:6.971(6.971), batch time:1.46(1.46), data load time: 0.00(0.00)
train 20/5004, loss:7.003(6.988), batch time:0.29(0.36), data load time: 0.01(0.01)
train 40/5004, loss:6.926(6.967), batch time:0.30(0.33), data load time: 0.01(0.01)
train 60/5004, loss:6.936(6.953), batch time:0.29(0.32), data load time: 0.01(0.01)
train 80/5004, loss:6.859(6.937), batch time:0.32(0.32), data load time: 0.02(0.02)
train 100/5004, loss:6.825(6.924), batch time:0.30(0.32), data load time: 0.02(0.02)

dali and i7-7800x + 2080ti*2:
train 0/1281167, loss:6.971(6.971), batch time:3.94(3.94), data load time: 0.00(0.00)
train 20/1281167, loss:6.987(6.990), batch time:0.23(0.38), data load time: 0.01(0.00)
train 40/1281167, loss:6.918(6.965), batch time:0.23(0.30), data load time: 0.00(0.00)
train 60/1281167, loss:6.919(6.949), batch time:0.19(0.27), data load time: 0.00(0.01)
train 80/1281167, loss:6.850(6.933), batch time:0.19(0.25), data load time: 0.00(0.00)
train 100/1281167, loss:6.829(6.919), batch time:0.20(0.24), data load time: 0.00(0.00)
train 120/1281167, loss:6.853(6.906), batch time:0.21(0.24), data load time: 0.00(0.00)
train 140/1281167, loss:6.832(6.894), batch time:0.23(0.23), data load time: 0.00(0.00)
train 160/1281167, loss:6.735(6.880), batch time:0.21(0.23), data load time: 0.01(0.00)
train 180/1281167, loss:6.751(6.867), batch time:0.19(0.22), data load time: 0.00(0.00)
train 200/1281167, loss:6.689(6.853), batch time:0.19(0.22), data load time: 0.00(0.00)
train 220/1281167, loss:6.608(6.836), batch time:0.20(0.22), data load time: 0.00(0.00)
train 240/1281167, loss:6.577(6.821), batch time:0.19(0.22), data load time: 0.00(0.00)
train 260/1281167, loss:6.581(6.806), batch time:0.22(0.22), data load time: 0.02(0.00)
train 280/1281167, loss:6.547(6.791), batch time:0.21(0.22), data load time: 0.00(0.00)
train 300/1281167, loss:6.574(6.777), batch time:0.18(0.22), data load time: 0.00(0.00)
train 320/1281167, loss:6.608(6.762), batch time:0.20(0.22), data load time: 0.00(0.00)
train 340/1281167, loss:6.561(6.747), batch time:0.21(0.21), data load time: 0.00(0.00)
train 360/1281167, loss:6.396(6.732), batch time:0.20(0.21), data load time: 0.00(0.00)

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



