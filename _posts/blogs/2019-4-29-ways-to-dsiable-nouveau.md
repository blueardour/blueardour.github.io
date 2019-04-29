---
layout: post
title: Disable nouveau
categories: configuration os
date: 2019-04-29 12:38:11
pid: 20190429-123811
pin: 14
# you can override the settings in _config.yml here !!
---

method to disable  nouveau

> grubby ––update-kernel=ALL ––args="rd.driver.blacklist=nouveau nouveau.modeset=0"
> mv /boot/initramfs-$(uname -r).img /boot/initramfs-$(uname -r).img.bak
> echo "blacklist nouveau" > /etc/modprobe.d/nouveau-blacklist.conf 
> dracut /boot/initramfs-$(uname -r).img $(uname -r)
> 
> reboot
