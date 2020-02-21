---
layout: post
title: Model Compression Comment
categories: model-compression ai quantization summary open
date: 2019-07-19 02:38:59
pid: 20190719-023859
pin: 33
# you can override the settings in _config.yml here !!
---

# Introduction

CNN are broadly employed in the computer vision, NLP and others areas. However, many redudance exists in the network. In other word, one could leverage less computing resources to finish the task without accuracy loss. Many publications come out for the simplification.

Quantization means to regress the activation or weight to several discrete set of number. Generally, quantization implies to fix point data type. In the publications, some focus on quantization on the weights, some others focus on the quantization on activation and also focus on both. Image classification is the most usual application to verify the algorithm, other scenarios such as detection, tracking, segmentation and even super resolution also attract attentions. Following summarize parts of the related papers.

Pruning is to delete certain links in the network. Sometimes the chosen links are random selected (unstructured pruning). Sometimes fixed pattern links are chosen (structured pruning), such as channel pruning.

Knowledge distill is another kind of model compression method. It employs a redudent network to train a smaller network. The former is a teacher while the latter as a student. It could combine with beforementioned quantization and pruning. For example, knowlege distill is used for obtain a low precision network with a full precision network as a teacher.

# Quantization

The first milestone in model compression is the 'Deep Compress' by Han Song in 2016. Researchers quickly implemented algorithms that 8bit is always good enough for classification prolem. Latter, extreme low bit (binary, ternary and 2bit) is studied. The reprensentive work includes BWN, BC, XNOR-net.

# Quantization by Structure 
However, binariezing a network cause huge drop in accuracy (more that 10 points). One way to resolve it is to increase the width of the network. Another way is to create seprate path for the origin networks, for example, the ABC-net and Group-Net. BiReal-net advises to add high precision skip to vgg-like network structure. All of these wants to increase the backprogation gradient to early layers as much as possible. 'How to train binary network' also mention the trcik of adding additional skip connection. They also recomend gradient clip and Prelu instead of Relu.
However, by my experiments, the PReLU seams to not work. HORQ is an improvement of Xnor-Net, to assign more bits to the residual.

# Quantization by data distribution
For quantization algorthms itself, HWGQ is famous for it propose the quantization based on the distribution of the activation or weights. Dorefa quantize activation, weight and even gradient to any bit. It is efficient and followed and employed by many other works. My training on Dorefa obtained much better result than the paper reported ones. Balanced Quantization force the different level value to have similair count (balance the distribution in each quantionzation center), which in my experiement seems to not work. Balanced Quantization even colide with some other work and doesn't convince me. 

PACT first propose to regress the activation to small range. The origion PACT paper only limit the maxumum of the activation. Traditionally, the maxumum value to be quantized could be computed offline by KL divergence(Nvidia ever open source its KL divergence code), or just multiple a scalar (such as 0.8) to the max of the activation. PACT advised the value learned dynamically during the training.

Latter the author of PACT come up with 'Accurate and efficint 2-bit quantization' for improvement. They proposed a seperate method for the weight and keeping PACT for the activation. QIL(Quanitzation Interval Loss) learn the upper and lower bound of the activation and weight. They additionally relax the the network with smooth function first to improve the performance.

# Better optimization method
In aspects of optimization, 'towards effitive low-bitwdith' propose to first quantize the weight and finetune to quantize the feature map. 'Two step quantization' also advise seperately quantize the weight and feature map. Their formulation is to make argmin \|y - Q(w) * X\|. 
I think it should revised to optimize \| y - Q(w)*Q(X) \|, however, this need further effort to evaluate.

# Regression
'ProxQuant' think the STE as a kind of lazy proection SGD. They proposed a better gradient method along with adding regression term. They introduce a hyperparameter to control how much the data should be quantized to dicrete level or regressed directly to dicrete level.

# ADMM
Take the quantization problem as an optimization problem.

# Close-form Quantization
'LQnet' is currently my favouriate method. 

# Loss-aware
Explicit loss-aware quantization for low bit deep nerual networks
Loss aware weight quantization of deep network

# Direction

1. (structure) network sturcutre search cooperated with quantization. Is it possible to add high resolution skip connection? How to increase the channel?
2. (task) other scenario such as object detetion and segmentation and pixel level tasks. Multiple loss function and even regression loss.
3. (optimizer) \|Y- Q(W)*Q(X)\|?
4. ADMM introduced by Leng Cong seems to be the regression type, which is bothered by hard converage. They solved it by sub-gradient.
5. initilization problem. Why fine-tunning from stratch give better result? How to initlize weight for quantization network?
6. different bit level for different layer. mix precision combines
7. Quantize networks without BN? By Fixup, the BN layer might be reduced from the network.
8. finetune low bit network with limited training data or even no data
9. how to deal with pad?
10. refer ProxQuant   Q'(x) = a * x + (1-a) * Q(x)
11. mobilnet-v1/2 non-uniform encoder vs  increase the channel number
12. tanh 'quantization network' in CVPR 2019.
