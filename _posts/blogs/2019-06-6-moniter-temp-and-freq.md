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

sudo hdparm -I /dev/sda

# check temp of SSD
sudo apt install smartmontools nvme-cli hddtemp
sudo nvme smart-log /dev/nvme0
sudo hddtemp /dev/sda

## enable test
sudo smartctl -s on -a /dev/sda

## self-test short or long
sudo smartctl -t short -a /dev/sda
sudo smartctl -t long -a /dev/sda

## Status
sudo smartctl -a /dev/sda

## samsung
https://www.samsung.com/semiconductor/minisite/ssd/download/tools/#ge_semi_anchor_stand5
