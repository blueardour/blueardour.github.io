---
layout: post
title: Non-convex optimization
categories: ai optimization blog
date: 2020-04-28 09:38:11
pid: 20200428-093811
pin: 45
# you can override the settings in _config.yml here !!
---

# Chapter 1. Introduction

Talk about what's non-convex optimization. Why study it? Most of practical problems can be modeled as non-convex optimization.

Two examples: the sparse recovery(find the independent fators or when given data item n << facotrs p), the recommond system (low rank matrix compeletion)

THe non-convex optimization can be solved by convex relaxation approch (for example LASSO formulation). note: structured problem lead to absent relaxation gap

# Chapter 2. Mathematical tools

## convex analysis

1. convex combination

2. convex set
![01](/w3c/images/blog/convex-set.jpg "A10")

3. convex function (must be continugous differentiable?) might not be continugous and differentiable
[https://www.zhihu.com/question/31437665](https://www.zhihu.com/question/31437665)

closed set has the min/max point. open set might not

a. strongly convex / strongly smooth (ss function is not must to be convex?) must to be convex. but might not derivated

[strongly convex must be strictly convex](https://math.stackexchange.com/questions/2090991/proof-for-strongly-convex-function-is-strictly-convex)
vise via not (https://math.stackexchange.com/questions/2194323/what-is-a-strictly-convex-function-that-is-not-strongly-convex)

y = |x| + x^2 is strongly convex, but not derivated at point zero

![02](/w3c/images/blog/sc-sm.jpg "A11")

b. Liptichitz function / Jensen inequality

![03](/w3c/images/blog/lipshitz.jpg "A11")

![04](/w3c/images/blog/Jensen.jpg "A11")

## convex project (are PPI/II/O require the project function to be norm-2?)

1.  first order properties: PPI/ PPII
![05](/w3c/images/blog/PPI.jpg "A11")

if z not in C, then the angle is not acute angle

![06](/w3c/images/blog/PPII.jpg "A11")

2. zeroth order property: PPO
![07](/w3c/images/blog/PPO.jpg "A11")

## projected gradient descent
![08](/w3c/images/blog/PGD.jpg "A11")

## convergence guarantees

# Chapter 3. non-convex projected gradient descent

## project sparse vector / low rank matrix

## restricted convext/ strong convex/ smooth

## convergence condition / speed

# Chapter 4. Alternating Minimization

## Marginal Convexity / Joint Convexity

## update step ? 


