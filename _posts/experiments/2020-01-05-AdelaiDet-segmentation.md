---
layout: post
title: COCO Segmentation
categories: training-trick experiments COCO segmentation
date: 2020-01-06 12:38:12
pid: 20200106-123812
pin: 40
# you can override the settings in _config.yml here !!
---

# Networks Accuracy trained

Paper | Dataset | Network | Bit(A/W/G) | Paper report | My Accuracy | Comment
----- | ---- | ---------- | ------ | -------  |  ---------  
 Mask-RCNN  | COCO | det-R18 | 32/32/32 | - | 31.442 | 1x fp16
 BlendMask  | COCO | det-R18 | 32/32/32 | - | 18.782 | 1x fp16, bs=12
 BlendMask  | COCO | det-R50 | 32/32/32 | - | 33.913 | 550-R-50-aux-1x, fp16
 BlendMask  | COCO | det-R50 | 32/32/32 | - | 36.116 | 550-R-50-aux-3x, fp16
 BlendMask  | COCO | det-R18 | 32/32/32 | - | 29.697 | 550-R-18-aux-1x-FPN-BN, fp16

