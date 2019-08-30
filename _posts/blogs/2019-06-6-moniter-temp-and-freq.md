---
layout: post
title: Monitor CPU/GPU/DDR freq and temperature in Linux
categories: cnn experiments
date: 2019-06-06 12:38:50
pid: 20190606-123850
pin: 27
# you can override the settings in _config.yml here !!
---

# DDR freq
sudo dmidecode --type 17

# CPU freq
lscpu | grep MHz

# CPU temperature
sensor

# Find out HDD or SSD
cat /sys/block/sda/queue/rotational

1: HDD
0: SSD

