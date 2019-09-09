---
layout: post
title: Training Log
categories: training-trick
date: 2019-06-25 12:38:11
pid: 20190625-123811
pin: 100
# you can override the settings in _config.yml here !!
---

# Current Task
1. archlab:
   2019.7.27 19:49
   #0,1: lqnet-fp-bacs-resnet50-0: 10010/0.78/120 (10.8d) 74.26
   2019.8.8 8:58
   #0,1: lqnet-fp-bacs-resnet50-1: 10010/0.43/120 (6d) 75.62
   2019.8.14 20:44
   #0,1: lqnet-fp-cbas-resnet50-1: 10010/0.43/120 (6d) 75.336
   2019.8.21 17:44
   #0,1: lqnet-fp-bacs-resnet50-2: 10010/0.43/120 (6d) done
   2019.09.02 13:44
   #0: alqnet-fp-mobilenet-v1 13345/0.27/120 (5.2d) done

   2019.09.08 08:44
   #0: alqnet-fp-mobilenet-v1 bacs 13345/0.30/120 (5.2d)

   2019.09.06 10:44
   #1: alqnet-fp-mobilenet-v1 bacs 13345/0.28/120 (5.2d)

2. server:
   2019.7.27 14:55
   #0: 10009/0.45/120 alqnet-2bit dali finetune poly (6.3d)
   #1: 10009/0.44/120 alqnet-2bit dali finetune sgdr
   2019.8.3 10:40
   #0: 10009/0.34/120 lqnet-2bit dali finetune sgdr done
   #1: 10009/0.98/120 alqnet-3bit dali finetune sgdr (13d) done 
   2019.8.8 10:12
   #0: 10009/0.27/120 alqnet-bin dali finetune sgdr (3.7d) done 52.948
   2019.8.12 10:43
   #0: 10009/0.52/120 lqnet-3bit dali finetune poly (6.9d) done
   2019.8.20 10:24
   #0: 10009/0.52/120 lqnet-3bit dali finetune custom-step (7d) done
   2019.8.17 11:24
   #1: 10009/0.98/120 alqnet-3bit dali finetune custom-step (13d) done
   2019.8.28 10:24
   #0: 10009/0.29/120 alqnet-2bit dali finetune custom-step (4.1d) done
   2019.9.02 11:24
   #1: 13345/0.33/120 alqnet-ter-resnet34 dali finetune custom-step (6.2d) done

   2019.9.02 11:24
   #0: 10009/0.55/120 alqnet-3bit-resnet18 dali finetune custom-step adam (7.6d)

   2019.9.09 11:24
   #1: 13345/0.45/120 lqnet-2bit-resnet34 dali finetune custom-step (8.4d)

3. ubuntu:
   2019.7.26 19:20
   #0: 10010/0.4/120 alqnet-a32w2-finetune-aa (5.6d)
   2019.8.2 8:40
   #0: 10010/0.48/120 alqnet-a32w3-finetune-aa (7d)
   2019.8.9 11:15
   #0: 10010/0.36/120 alqnet-a32w1-finetune (5d)
   2019.8.15 11:28
   #0: 10010/0.46/120 alqnet-a32w3-finetune (7d)
   2019.9.1 09:51
   #0: 10010/0.46/120 alqnet-a32w3-finetune (7d) done

4. anton:
   #0: 10010/0.49/84 lqnet-a2w1
   2019.7.26 19:56
   #0: 10010/0.26/120 lqnet-a32w2-finetune-aa-poly (3.6d)
   2019.7.31 9:20
   #0: 10010/0.26/120 lqnet-a32w3-finetune-aa-poly (4.2d)
   2019.8.5 10:20
   #0: 10010/0.36/120 lqnet-bin-finetune-aa-poly (5d) 53.846
   2019.8.10 17:08
   #0: 10010/0.36/120 lqnet-bin-finetune poly (5d) 54.7
   2019.8.17 11:43
   #0: 10010/0.52/120 alqnet-ter-finetune sgdr v1 (7d)
   2019.8.25 11:43
   #0: 10010/0.75/120 alqnet-2bit-resnet34 custom-step v2 (10.3d)
   #0: 10010/0.76/76 alqnet-2bit-resnet34 custom-step v2 (?) done

   2019.9.5 10:33
   #0: 10009/0.30/120 alqnet-bin dali finetune sgdr (4.2d)

5. level4:
   2019.8.1 09:00
   #0: 10009/0.51/120 lqnet-2bit dali finetune poly (7d)
   2019.8.8 10:06 (stopped at 8.12 11:00)
   2019.8.12 11:00  change to new lr policy
   #3: 10009/0.4/115 alqnet-bin dali finetune poly (continue, 5.4d) done 53.856
   #0: 10009/0.35/120 lqnet-bin dali finetune sgdr (4.9d) done 51.122
   2019.8.17 19:43
   #1: 10010/0.53/120 alqnet-ter-finetune poly v0 (7d) done
   2019.8.21 17:43
   #0: 10009/0.35/120 lqnet-bin dali finetune custom-step (4.9d) done
   2019.9.5 10:33
   #0: 10009/0.35/70 lqnet-bin dali finetune custom-step (2.8d) done

   2019.9.8 10:33
   #1,2: 6672/0.4/150 mobilenet-v2 poly (4.7d)

6. phoenix: 
   2019.7.27 14:55 / 2019.8.5 10:20
   #2 volta: alqnet-fp-resnet34 (done)
   #1 volta: alqnet-fp-mobilenet-v1 (69.8, done)
   #1 volta: lqnet-3bit v1 sgdr  (10010 * 1 * 120) done
   #1 volta: alqnet-3bit v0 poly (10010 * 0.77 * 120) done
   #2 volta: alqnet-2bit-resnet34 v1 sgdr 70.656 done
   #1 volta: alqnet-fp-mobilenet-v1 done
   #1 volta: alqnet-ter v2 custom-step 10010/0.73/120 done
   #2 volta: alqnet-3bit v3 poly       10010/0.87/120 done
   #1 volta: lqnet-2bit v3 custom-step 10010/0.28/120 done

   #2 volta: fp-mobilenet-v2 5005/0.71/150 (6.2d)

   #2 volta: alqnet-3bit resnet50 custom-step 10010/1.40/120 (19.4d)
   #2 volta: alqnet-2bit resnet50 custom-step 10010/1.40/120 (queue)
   #1 volta: alqnet-3bit resnet34 custom-step 10010/0.79/120 (11.5d)

7. bai:
   2019.8.1 16:50
   #0: 10009/0.3/120 alqnet-bin dali finetune poly (abrupt)

   2019.8.8
   # test apex

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



