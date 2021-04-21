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
2. server:
   #2 volta: AdelaideDet blendmask coco R18-FPN-1x-fp16 det-resnet18 (done)
   #2 volta: AdelaideDet blendmask coco 550-FPN-1x-fp16 det-resnet50 (done)
   #2 volta: AdelaideDet blendmask coco 550-FPN-3x-fp16 det-resnet50 (done)
   #2 volta: AdelaideDet blendmask coco 550-FPN-1x-fp16-FPN-BN det-resnet18 (done)
   #2 volta: popcount-net r18 hoqr bcas fp32 sgd-0 (done)
   #1 volta: resnet18 hoqr++ xnor++ finetune bin bcas adam-0 and sgd-9 (done)
   #1 volta: det-resnet18 dorefa tet 3bit fcos sgd-9 O1 fp16 wt-mean-var (stop)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 wt-var wtet (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 wt-non wtet (done)
   #2 volta: AdelaideDet fcos coco R18-FPN-1x-FPN-BN-fp16-input det-resnet18 (done)
   #2 volta: AdelaideDet fcos coco R18-FPN-1x-FPN-BN-fp16 det-resnet18 round2 (done)
   #1 volta: SR EDSR baseline 2x
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 wt-var wtet static-bn


4. anton:
   #1 volta: popcount-net r18 hoqr bacs fp32 sgd-0 (done)
   #1 volta: resnet18 hoqr++ xnor++ finetune bin bacs adam-0 and sgd-9 (done)
   #1 volta: resnet18 dorefa tet bin bacs sgd-9 O1 fp16 wt-var
   #1 volta: resnet18 dorefa tet bin bacs sgd-9 O1 fp16 wt-var wtet

5. level4:
   #1 volta: det-resnet50 popcount ter fcos sgd-3 FP16 wt-adaptive mean-var

6. phoenix:
   chenp:
   #2 voltap: AdelaideDet fcos R18-FPN-1x-FPN-BN fp16 dorefa tet 2bit double-init backbone-only (done)
   #2 voltap: AdelaideDet fcos R18-FPN-1x-FPN-BN fp16 popcount ter double-init backbone-only (done)
   #2 voltap: AdelaideDet fcos R18-FPN-1x-FPN-BN fp16 dorefa tet 2bit double-init backbone-fpn (done)
   #2 voltaM: AdelaideDet fcos R18-FPN-1x-FPN-BN fp16 popcount bs=32 double-init backbone-only (done)
   #2 voltap: AdelaideDet fcos R18-FPN-1x-FPN-BN fp16 dorefa tet 2bit double-init all (done)
   #4 kepler: AdelaideDet retina-net R18-FPN-1x-FPN-BN-Head-GN det-resnet18 FP32 (done)
   #2 voltap: AdelaideDet fcos R18-FPN-1x-FPN-BN fp16 popcount double-init all (done)
   #2 voltap: AdelaideDet fcos R18-FPN-1x-FPN-BN det-resnet18 fp16 dorefa tet 2bit lr=2.5e-3 double-init all (done)
   #2 voltaM: AdelaideDet retina R18-FPN-1x-FPN-BN fp16 dorefa tet 2bit double-init all (done, error in config, mAP=8)
   #1 voltaM: det-resnet50 dorefa tet 2bit fcos sgd-9 O1 fp16 wt-mean-var (stop) 
   #1 voltaM: det-resnet50 dorefa tet 3bit fcos sgd-9 O1 fp16 wt-mean-var (stop)
   #2 volta: AdelaideDet fcos coco R18-FPN-1x-FPN-BN-fp16 det-resnet18 round3
   #1 volta: det-resnet18 dorefa tet 3bit fcos sgd-9 O1 fp16 wt-var wtet
   #1 volta: SR EDSR paper 2x

   bohan:
   #1 voltap: det-resnet18 dorefa tet 2bit wt-var wtet sgd-9 O1 fp16 (done)
   #1 voltap: det-resnet34 dorefa tet 2bit wt-var wtet sgd-9 O1 fp16 (done)
   #2 voltap: AdelaideDet fcos R18-FPN-1x-FPN-BN fp16 dorefa tet 2bit double-init all wtet (done)
   #2 voltap: det-resnet50 dorefa tet 2bit wt-var wtet sgd-9 O1 fp16
   #2 voltap: det-resnet50 dorefa tet 3bit wt-var wtet sgd-9 O1 fp16

# 2020.02.07
1. archlab:

2. server:
   #1 volta: det-resnet34 dorefa tet 2bit fcos sgd-9 O1 fp16 wt-mean-var (done)
   #1 volta: det-resnet18 dorefa tet 2bit fcos sgd-9 O1 fp16 wt-mean-var (done)
   #1 volta: resnet18 non-uniform baseline lqnet bacs 2bit sgd-1 O0 fp32 wt-mean-var epoch24 65.226 (done)
   #1 volta: resnet18 non-uniform baseline lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 (done) 
   #1 volta: resnet18 non-uniform loop2    lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 (done)
   #1 volta: resnet18 non-uniform FixWithGrad lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 round2 (done)
   #1 volta: resnet18 non-uniform FixWithGrad lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 round4 (done)
   #1 volta: resnet18 spatial lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 quant-group 4 (done)
   #1 volta: resnet18 spatial lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 quant-group 8 (done)
   #2 volta: AdelaideDet fcos coco R18-FPN-1x-Full-BN-fp16 det-resnet18 FP16 O1 (done)
   #2 volta: AdelaideDet retina-net coco R18-FPN-1x-fp16 det-resnet18 FP16 O1 (done)
   #2 volta: AdelaideDet fcos coco R18-FPN-1x-fp16 det-resnet18 FP16 O1 (done)
   #2 volta: AdelaideDet mask-rcnn coco R18-FPN-1x-fp16 det-resnet18 FP16 O1 (done)

3. centos:

4. anton:
   #1 volta: resnet18 non-uniform FixWithGrad lqnet bacs 2bit sgd-1 O0 fp32 wt-mean-var epoch24 (done)
   #1 volta: resnet18 non-uniform FixWithGrad lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 (done)
   #1 volta: resnet18 non-uniform FixWithGrad lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 round3 (done)
   #1 volta: resnet18 non-uniform FixWithGrad lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 round5 (done)
   #1 volta: resnet18 non-uniform FixWithGrad lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 round6 (done)
   #1 volta: resnet18 spatial-8 lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 (done)

5. level4:
   #1 volta: det-resnet34 popcount ter fcos sgd-3 FP16 wt-adaptive mean-var (done)
   #1 volta: resnet18 lqnet bacs sgd-1 FP32 fm-quant-group=8 spatial stratch (done)

6. phoenix:
   chenp:
   #2 voltap: AdelaideDet fcos coco R34-FPN-1x det-resnet34 (done)
   #4 kepler: AdelaideDet fcos coco R18-FPN-1x det-resnet18 (done)
   #4 kepler: AdelaideDet fcos coco R18-FPN-1x det-resnet18 popcount backbone only ter (done)
   #1 voltap: resnet18 non-uniform gradscale lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 (done)
   #4 kepler: AdelaideDet fcos coco R18-FPN-1x det-resnet18 popcount backbone only ter lr 1e-3 (done)
   #1 voltap: resnet18 non-uniform gradslope lqnet bacs 2bit sgd-4 O0 fp32 wt-mean-var epoch30 (done)
   #2 voltaM: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 wt-mean-var bs 1024 (done)
   #2 voltap: AdelaideDet retina-net coco R50-FPN-1x MSRA-R50 O1 fp16 (done)

   bohan:
   #2 voltaM: AdelaideDet fcos coco R18-FPN-1x-FPN-BN det-resnet18 (done)
   #2 voltaM: AdelaideDet fcos coco R18-FPN-1x-Full-BN det-resnet18(done)
   #2 voltaM: AdelaideDet fcos coco R18-FPN-1x-FPN-BN det-resnet18 ter backbone only popcount
   #2 voltaM: AdelaideDet fcos coco R18-FPN-1x-Full-BN det-resnet18 ter backbone only popcount

# 2020.01.18
1. archlab:
   #0 volta: fixup origin project r18, expect 2019.12.01 (done)
   #0 volta: mobilenet-v1 lqnet 2bit point-wise-only cbas  2019.12.11 (done)
   #0 volta: mobilenet-v1 lqnet 2bit point-wise-only cbas  sgd-1 (done)
   #1 volta: adaptive lqnet r18 [mean-fm] bacs 2bit lr-1 expect: 2020.01.05 (done)
   #1 volta: adaptive lqnet r18 bacs fp16 fix fix-pooling patch-stem singleconv sgd-1 (done)
   #1 volta: dorefa tet r18 bacs 2bit fix fix-pooling patch-stem singleconv sgd-4 (done)
   #2 volta: resnet50 popcount ter fcos sgd-3 FP16 wt-adaptive mean-var (move from level4)

2. server:
   #0,1 volta: R50 coco R-50-aux-3x.yaml bs=8 (done)
   #0,1 volta: fixup popcount r50 2019.11.29 (done)
   #1 volta: resnet18 pact a4w1 bacs adam-0 2019.12.06 (done)
   #0 volta: resnet18 dorefa a4w1 bacs sgd-2 2019.12.06(done)
   #0,1 volta: R18 adaptive lqnet 4bit bacs bs=256 sgd-2 (done)
   #0 volta: R18 adaptive lqnet 2bit bacs loop2 debug (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-5 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs fix-pooling patch-stem wd:1e-4 sgd-4 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs fix-pooling patch-stem wd:2e-5 sgd-4 (move to anton)
   #2 volta: AdelaideDet coco fcos-R-50-1x.yaml bs=8 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-8 wd:2e-5 mixup:0.7 epoch:60 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs fix-pooling patch-stem wd:1e-4 mixup:0.7 epoch:90 sgd-7 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 wd:2e-5 epoch:40 O1 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 grad-type: bug-A (divergence)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 grad-type: bug-B (div zero error)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 grad-type: none (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 grad-type: none scale5-fan (done)

3. centos:
   #0 volta: resnet18 dorefa a4w1 bacs sgd-3 90\*10010\*0.44  (done)
   #0 volta: fixup popcount r18 no mixup (done)
   #1 volta: resnet18 lqnet adaptive [fm-min] bacs 2bit lr-1 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-4 O1 fp16 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-4 grad-scale fan-scale2 O1 fp16 (not converage)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-4 grad-scale mean-fan-scale2 O1 fp16 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-9 O1 fp16 grad-type: none scale2-fan

4. anton:
   #0 volta: R50 coco 550-R-50-aux-3x.yaml  bs=8 (done)
   #1 volta: mobilenet-v1 dorefa 4bit cbas adam 0 2019.12.09 (done)
   #1 volta: resnet18 lqnet adaptive [wt-mean-var] bacs 2bit lr-1 (done)
   #1 volta: resnet18 lqnet adaptive [enhance-info] bacs fp32 sgd-0 (done)
   #1 volta: resnet18 lqnet adaptive [enhance-info] bacs 2bit sgd-6 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs fix-pooling patch-stem wd:2e-5 sgd-4 (done)
   #1 volta: resnet18 popcount ter fcos sgd-3 FP16 (done)
   #3 volta: resnet18 dorefa tet 2bit bacs sgd-4 grad-scale mean-fan-scale1 O1 fp16 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-4 O1 fp16 full-gradient (done)
   #0 volta: resnet18 popcount ter bacs sgd-3 FP16 wt-adaptive mean-var s=0.625 (done)
   #0 volta: resnet18 popcount ter bacs sgd-1 FP16 wt-adaptive mean-var s=0.625 (done)

5. level4:
   #3 volta: resnet18 dorefa tet 2bit bacs sgd-4 grad-scale fan-scale1 O1 fp16 (stopped, not converage)
   #0 volta: resnet18 popcount ter fcos sgd-3 FP16 wt-adaptive mean-var (done)
   #0 volta: resnet18 popcount ter fcos sgd-3 FP16 wt-adaptive mean-var s=0.625 (done)
   #1 volta: resnet34 popcount ter fcos sgd-3 FP16 wt-adaptive mean-var

6. phoenix:

   chenp:
   #2 volta: lqnet mobilenetv1 fg=8 pto 2bit cbas (done)
   #1 acvts: lqnet mobilenetv1 fg8wg8 dpo 2bit cbas (done)
   #1 acvts: lqnet mobilenetv1 fg1wg1 dpo 2bit cbas (done)
   #1 volta: fixup popcount r18 with mixup (done)
   #1 volta: mobilenetv1 fp cbas gn16 (done)
   #1 volta: mobilenetv1 fp cbas gn8 (done)
   #1 volta: adaptive lqnet r18 [fm-mean] bacs 2bit lr-1 (done)
   #1 volta: lqnet mobilenetv1 fg1wg1 dpo pt 2bit cbas sgd-0 clr(c) (done)
   #1 volta: lqnet mobilenetv1 fg1wg1 dpo pt 2bit cbas sgd-1 (b) (done)
   #1 volta: lqnet mobilenetv1 fg1wg1 dpo pt 2bit cbas directly(a) (done)
   #4 volta: FCOS fcos-imprv-R-50-FPN-1x (give up, switch to detectron)
   #2 volta: AdelaideDet retina coco R50-FPN-1x (done)
   #2 volta: AdelaideDet coco fcos-R-50-1x.yaml bs=16 (done) 25GB per GPU = 50GB GPU memory
   #2 volta: AdelaideDet retina coco R50-FPN-1x-round2 det-resnet50 (done)
   #2 volta: AdelaideDet retina coco R50-FPN-1x-round3 det-resnet50 (done)
   #2 volta: AdelaideDet retina coco R18-FPN-1x-round2 det-resnet18 14GB per GPU = 28GB GPU memory (done)

   liangyi:
   #1 volta: resnet18 lqnet adaptive [wt-mean] bacs 2bit lr-1 (done)
   #0 volta: resnet18 dorefa 2bit bacs sgd-4 (done)
   #1 volta: resnet18 dorefa tet 2bit bacs sgd-4 O0 fp32 (done)
   #2 volta: AdelaideDet coco retina-R-18-1x.yaml bs=16 (done)

   bohan:
   #1 volta: resnet18 lqnet adaptive [fm-var] bacs 2bit lr-1 (done)
   #2 volta: AdelaideDet coco retina-R-34-1x.yaml bs=16 (done)
   #2 volta: AdelaideDet coco retina-R-34-1x.yaml bs=32 round2 lr=0.04 (done)
   #2 volta: AdelaideDet coco retina-R-34-1x.yaml bs=16 round3 (done) 16GB per GPU = 32GB GPU memory
   #2 volta: AdelaideDet coco retina-R-34-1x.yaml bs=16 round4 (done)

# history Task
1. archlab:
   2019.9.29 11:24 
   #0,1: 6672/0.32/120 resnet34 custom-step alqnet 3bit (expect 2019.10.12) (paused)
   #2 volta: bireal34 cbsa fp 120*5004*0.4 = 2.8d(on 2019.10.09 3:20pm) (done) 
   #1 volta: bireal34 bireal   cbsa fp 120*10009*0.50 = 7d (expect 2019.10.30) (done)
   #1 volta: bireal34 popcount cbsa fp 120*10009*0.48 = 7d (expect 2019.10.30) (done)
   #1 volta: bireal34 bireal   cbsa fp 120*10009*0.52 = 4.5d s=0.625 (done)
   #1 volta: bireal34 popcount cbsa fp 120*10009*0.50 s=0.625  expect 11.12 (stopped)
   
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
   #1 volta: mobilenet v1 bacs ter popcount depth-skip s=0.5 done
   #1 volta: resnet18 bacs ter popcount s=0.625 (done)
   #1 volta: resnet34 bacs ter bireal s=0.625 (done)
   #0 volta: resnet18 bacs 2bit group-norm quant-group=8
   #1 volta: resnet18 bacs 2bit quant-group=8
   #0 volta: resnet18 bacs ter fp16 popcount s=0.625 (done) 
   #1 volta: resnet34 bacs ter fp16 popcount s=0.625 (done)

3. centos:
   #1 volta: resnet18 bacs fp group-net group-norm=4 sgd-2 (done)
   #1 volta: resnet18 bacs fp group-net group-norm=8 sgd-2 (done)
   #1 volta: resnet18 bacs fp group-net group-norm=4 sgd-1 (done)

4. anton:
   #1 volta: bireal18 cbsa fp  8007 * 0.22 * 120 =  (done)
   #1 volta: resnet18 bacs 2bit alqnet quant-group: -8 (expect: 10.17) (done)
   #1 volta: resnet18 bacs ter popcount s=0.75(done)
   #1 volta: resnet18 bacs ter popcount s=0.50(done)
   #1 volta: resnet18 bacs ter popcount s=0.5 finetune wt-group=1 (done)
   #1 volta: resnet18 bacs ter bireal s=0.625 (done)
   #1 volta: resnet18 bacs a32w2 bireal s=0.625 (done)

5. level4:
   #1 volta: bireal18 cbsa ter popcount (done)
   #1 volta: mobilenet v1 bacs fp depth-skip (13345 * 0.39 * 120 = 7.3d) (done)
   #1 volta: resnet18 bacs ter popcount s=0.5 stratch wt-group=1 (done)
   #1 volta: bireal18 cbsa ter popcount s=0.625 (120-49) * 10009 * 0.31 (expect before 11.04) (done)
   #1 volta: bireal18 cbsa ter bireal s=0.625 (expect 11.09)

6. phoenix: 
   #2 volta: mobilenet v2 bacs fp (done)
   #2 volta: mobilenet v1 cbas 2bit (stopped for bad performance)
   #1 volta: mobilenet v1 bacs 2bit alqnet (stopped for bad performance)
   #1 volta: resnet18 bacs 2bit alqnet quant-group: -64 (paused as disk too slow, decide to cancel task)
   #1 volta: resnet18 bacs 2bit alqnet quant-group: -1 (stopped, as result is Nan) (Nan is not out of expection, as only ks*ks data participate the quantization)
   #2 volta: resnet34 cbsa fp (paused as gpu too slow) (task is re-submitted on archlab)

   cp:
   #2 volta: resnet50 bacs ter popcount s=0.5 finetune (done)

   bohan:

   liangyi:
   #1 volta: mobilenet v1 cbas fp depth-skip (done)
   #2 volta: resnet34 bacs ter popcount s=0.625 (5005 * 0.35 * 120) (done)
   #2 volta: resnet50 bacs ter popcount s=0.625 finetune (done)
   #2 volta: resnet18 bacs fp popcount alpha=2 (done)
   #2 volta: resnet18 bacs ter popcount alpha=2 
   #2 volta: Fixup R50

# CMD:
python tools.py --keyword update,raw,imagenet,origin,preBN,bacs --model resnet18 --pretrained weights/resnet18/dali-dorefa-stratch-fp-bacs_0-model_best.pth.tar --new weights/resnet18/cls_r18.pth --case backbone.bottom_up.

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



