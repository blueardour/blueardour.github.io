---
layout: post
title: Post-Training Quantization for Vision Transformer
categories: quantization ai cv model-compression transformer
date: 2022-04-04 02:38:59
pid: 20220404-023859
pin: 53
# you can override the settings in _config.yml here !!
---

# Introduction

1. Post-Training Quantization for Vision Transformer
[paper](https://arxiv.org/pdf/2106.14156.pdf)

2. Tips:

  a. Similarity-Aware Quantization for Linear Operation. we adopt Pearson correlation coefficient as the measurement for the similarity

  b. Ranking-Aware Quantization for Self-Attention.

  c. Bias Correction

3. Similiar

  a. I-BERT: Integer-only BERT Quantization: Polynomial Approximation of Non-linear Functions

  b. 
