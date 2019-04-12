---
layout: post
title: Feedforward semantic segmentation with zoom-out features
categories: ai segmentation
date: 2019-04-12 13:38:11
pid: 20190412-133811
pin: 4
# you can override the settings in _config.yml here !!
---

(CVPR 2015)

This paper and the FCN are both published on the CVPR 2015. While the latter is released on the axrive early, so the former cites the result from the latter one. In the contribution, it claims great improvement over the conventional algorithm, but in fact only 2 point versus the FCN. It still employs the superpixel which is the mainstream in image segmentation before CNN is massively used. It seems that this paper is the last one to continue to leverage the superpixel. Afterward papers all turn to deep learning.

I think the main reason is that they take a lot of maunal designed feature map, not end to end learnable ones. It is bad for robust and extension. Besides, so called superpixels could not express the combination of global and local information. Their code seems not to make public.

The idea behind the paper could be illstruted by the following image:
![zoom out](/w3c/images/paper/zoom-out.png "zoom out")

Useful link:
1. [https://blog.csdn.net/u014451076/article/details/79462950](https://blog.csdn.net/u014451076/article/details/79462950)
2. [https://blog.csdn.net/wydbyxr/article/details/80614948](https://blog.csdn.net/wydbyxr/article/details/80614948)


