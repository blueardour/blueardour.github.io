---
layout: post
title: Convert between pytorch onnx and caffe
categories: cnn experiments
date: 2019-06-06 12:38:11
pid: 20190606-123811
pin: 26
# you can override the settings in _config.yml here !!
---

# step1. pytorch to onnx
all the experiments are done with jupyter. If you don't like it, you could directly use the terminal or any python enviroment.
![step1](/w3c/images/experiments/pytorch-onnx-caffe01.png "step1")

# step2. regress the onnx model to be more clean and neat by onnx-simplier
require: https://github.com/daquexian/onnx-simplifier
note: advise to checkout to 1.3.0
![step2](/w3c/images/experiments/pytorch-onnx-caffe02.png "step2")

# step3. onnx to caffe
require: https://github.com/MTlab/onnx2caffe
note: the repo seems to have some bugs, contact me to request the modified version
note: this step require caffe with python interface. What's more, the official version doesn't have some layer types, for example the Interp layer. Thus, you have to build the custom version of caffe or contact me to ask for the pre-built custom version
note: the step1 and step2 employ python3. however caffe requires python2, thus this step requires to python2
![step3](/w3c/images/experiments/pytorch-onnx-caffe03.png "step3")

# step4. how to check the result matches with original pytorch(optional)
![step4](/w3c/images/experiments/pytorch-onnx-caffe04.png "step4")

# extra
[install python via pyenv](https://stackoverflow.com/questions/46959072/installing-pip-python-3-6-3-ubuntu-16-04-zlib-not-available-but-its-installed)
