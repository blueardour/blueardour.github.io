---
layout: post
title: COCO Detection
categories: training-trick experiments COCO detection
date: 2020-01-06 12:38:11
pid: 20200106-123811
pin: 39
# you can override the settings in _config.yml here !!
---

# Networks Accuracy trained

Paper | Dataset | Network | Bit(A/W/G) | Paper report | My Accuracy | Comment
----- | ---- | ---------- | ------ | -------  |  ---------  
 Retina-Net | COCO | MSRA-R50 | 32/32/32 | - | 36.465 | 1x
 Retina-Net | COCO | det-R50 | 32/32/32 | - | 35.070 | 1x round2
 Retina-Net | COCO | det-R50 | 32/32/32 | - | 36.564 | 1x round3
 Retina-Net | COCO | det-R50 | 32/32/32 | - | 37.765 | 1x-Full-BN syncbn bs=8 double-iteration lr=0.005
 Retina-Net | COCO | det-R34 | 32/32/32 | - | 31.661 | 1x 
 Retina-Net | COCO | det-R34 | 32/32/32 | - | 30.134 | 1x round2
 Retina-Net | COCO | det-R34 | 32/32/32 | - | 33.240 | 1x round3
 Retina-Net | COCO | det-R34 | 32/32/32 | - | 35.168 | 1x round4
 Retina-Net | COCO | det-R18 | 32/32/32 | - | 27.488 | 1x 
 Retina-Net | COCO | det-R18 | 32/32/32 | - | 31.523 | 1x round2
 Retina-Net | COCO | det-R18 | 32/32/32 | - | 08.491 | 1x fp16
 Retina-Net | COCO | det-R18 | 32/32/32 | - | 32.681 | 1x FPN-BN
 Retina-Net | COCO | det-R18 | 32/32/32 | - | 32.983 | 1x Full-BN
 FCOS       | COCO | MSRA-R50 | 32/32/32 | - | 36.002 | 1x bs=8
 FCOS       | COCO | MSRA-R50 | 32/32/32 | - | 38.561 | 1x
 FCOS       | COCO | MSRA-R50 | 32/32/32 | - | 09.990 | 1x fp16
 FCOS       | COCO | det-R50 | 32/32/32 | - | 38.349 | 1x
 FCOS       | COCO | det-R50 | 32/32/32 | - | 35.146 | 1x fp16, FPN-BN, bs=8
 FCOS       | COCO | det-R50 | 32/32/32 | - | 38.451 | 1x FPN-BN
 FCOS       | COCO | det-R50 | 32/32/32 | - | 38.894 | 1x Full-BN
 FCOS       | COCO | det-R34 | 32/32/32 | - | 37.313 | 1x
 FCOS       | COCO | det-R18 | 32/32/32 | - | 32.157 | 1x, bias on
 FCOS       | COCO | det-R18 | 32/32/32 | - | 31.819 | 1x, bias off
 FCOS       | COCO | det-R18 | 32/32/32 | - | 33.350 | 1x FPN-BN
 FCOS       | COCO | det-R18 | 32/32/32 | - | 33.909 | 1x Full-BN
 FCOS       | COCO | det-R18 | 32/32/32 | - | 23.713 | 1x Full-BN round2 bs=12
 FCOS       | COCO | det-R18 | 32/32/32 | - | 33.759 | 1x Full-BN round3
 FCOS       | COCO | det-R18 | 32/32/32 | - | 34.271 | 1x Full-BN round4 syncbn
 FCOS       | COCO | det-R18 | 32/32/32 | - | 33.504 | 1x fp16
 FCOS       | COCO | det-R18 | 32/32/32 | - | 33.865 | 1x FPN-BN-fp16
 FCOS       | COCO | det-R18 | 32/32/32 | - | 33.488 | 1x FPN-BN-fp16 round2
 FCOS       | COCO | det-R18 | 32/32/32 | - | 32.901 | 1x FPN-BN-fp16 round3 RELU-INPLACE-False
 FCOS       | COCO | det-R18 | 32/32/32 | - | 32.786 | 1x FPN-BN-fp16-input
 FCOS       | COCO | det-R18 | 32/32/32 | - | 18.593 | 1x Full-BN-fp16 round1
 FCOS       | COCO | det-R18 | 32/32/32 | - | 26.671 | 1x Full-BN-fp16 round2
 FCOS       | COCO | det-R18 | 32/32/32 | - | 26.149 | 1x Full-BN-fp16 round3 single-GPU
 FCOS       | COCO | det-R18 | 2/2/32 | - | 32.549 | 1x FPN-BN fp16 dorefa-tet backbone-only
 FCOS       | COCO | det-R18 | 2/2/32 | - | 33.384 | 1x FPN-BN fp16 dorefa-tet backbone-only round2
 FCOS       | COCO | det-R18 | 2/2/32 | - | 31.786 | 1x FPN-BN fp16 dorefa-tet backbone-fpn
 FCOS       | COCO | det-R18 | 2/2/32 | - | 30.333 | 1x FPN-BN fp16 dorefa-tet whole
 FCOS       | COCO | det-R18 | 2/2/32 | - | 26.334 | 1x FPN-BN fp16 dorefa-tet whole lr=2.5e-3
 FCOS       | COCO | det-R18 | 2/2/32 | - | 31.981 | 1x FPN-BN fp16 dorefa-tet whole wtet
 FCOS       | COCO | det-R18 | ter/ter/32 | - | 26.494 | 1x, bias on , pocount backbone only
 FCOS       | COCO | det-R18 | ter/ter/32 | - | 26.149 | 1x, bias off, pocount backbone only
 FCOS       | COCO | det-R18 | ter/ter/32 | - | 19.657 | 1x, bias off, pocount backbone only, lr=1e-3
 FCOS       | COCO | det-R18 | ter/ter/32 | - | 31.355 | 1x FPN-BN fp16 popcount backbone-only
 FCOS       | COCO | det-R18 | ter/ter/32 | - | 32.579 | 1x FPN-BN fp16 popcount backbone-only bs=32
 FCOS       | COCO | det-R18 | ter/ter/32 | - | 26.171 | 1x FPN-BN fp16 popcount whole


 1. export PYTHONWARNINGS='ignore:semaphore_tracker:UserWarning'


