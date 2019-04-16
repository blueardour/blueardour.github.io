---
layout: post
title: Secure Boot
categories: configuration os
date: 2019-04-16 12:38:11
pid: 20190416-123811
pin: 7
# you can override the settings in _config.yml here !!
---

# Introduction
Recently, I got a new computer which is pre-installed with Win10. Enven thought I don't like versions higher than WIn7, it was not worth for me to re-install a new one. Thus I kept the Win10 and also installed two other OS: the Ubuntu18.04 and Centos7.5. However, during the installation, a EFI partition was forced to seperate. Util then, I didn't realized the secure boot.

I'm very familiar with the bios boot up process, as I ever developed the OS from stratch. However, I'm not famailar with the UEFI boot which is default for the Win10. 

# Brief history of UEFI boot:

[https://wiki.ubuntu.com/UEFI/SecureBoot](https://wiki.ubuntu.com/UEFI/SecureBoot)

# Option meaning in the BISO
When secure boot is enable in the BISO, there are some options to be choosen, such as 'PK', "MOK". At first I don't know their meaning and also don't know how to configure. Then I found this post useful. [https://zhuanlan.zhihu.com/p/25279889](https://zhuanlan.zhihu.com/p/25279889)


# Relationship bewteen UEFI, BISO and secure boot

I found these posts useful.

[https://blog.csdn.net/qq_35038153/article/details/78440189](https://blog.csdn.net/qq_35038153/article/details/78440189)

[http://www.wobenben.com/html/news/201503/10290_1.html](http://www.wobenben.com/html/news/201503/10290_1.html)

# practice

When install new kernel mod, such as hardware drivers, the mainstream OS required signature of the mod. It means one should enroll some public key in the BISO and equip the mod with privated key. Then the OS know the mod is exactly the instance you need, rather than some unexpect one. It makes the OS more security and void attach from hackers.

However, it also caused certain trouble to install kernel mod, such as nvidia gpu drivers. To signature the mod, there are several steps. [https://askubuntu.com/questions/1023036/how-to-install-nvidia-driver-with-secure-boot-enabled](https://askubuntu.com/questions/1023036/how-to-install-nvidia-driver-with-secure-boot-enabled)


> Try this:
> 
> - Step 1: Download latest driver from NVIDIA website, https://www.geforce.com/drivers.
> 
> - Step 2: Create new pair private key (Nvidia.key) and public key (Nvidia.der) by entering command:
> 
> `openssl req -new -x509 -newkey rsa:2048 -keyout PATH_TO_PRIVATE_KEY -outform DER -out PATH_TO_PUBLIC_KEY -nodes -days 36500 -subj "/CN=Graphics Drivers"`
> 
> Example:
> 
> `openssl req -new -x509 -newkey rsa:2048 -keyout /home/itpropmn07/Nvidia.key -outform DER -out /home/itpropmn07/Nvidia.der -nodes -days 36500 -subj "/CN=Graphics Drivers"`
> 
> - Step 3: Enroll public key (nvidia.der) to MOK (Machine Owner Key) by entering command:
> 
> `sudo mokutil --import PATH_TO_PUBLIC_KEY`
> 
> Example:
> 
> `sudo mokutil --import /home/itpropmn07/Nvidia.der`
> 
> --> This command requires you create password for enrolling. Afterwards, reboot your computer, in the next boot, the system will ask you enroll, you enter your password (which you created in this step) to enroll it. Read more: https://sourceware.org/systemtap/wiki/SecureBoot
> 
> - Step 4: For the first time install NVidia driver, you need to disable Nouveau kernel driver by entering command:
> 
> `echo options nouveau modeset=0 | sudo tee -a /etc/modprobe.d/nouveau-kms.conf; sudo update-initramfs -u`
> 
> --> Reboot.
> 
> -Step 5: Install driver by entering command
> 
> `sudo sh ./XXXXXX.run -s --module-signing-secret-key=PATH_TO_PRIVATE_KEY --module-signing-public-key=PATH_TO_PUBLIC_KEY`
> 
> where:
> 
> XXXXXX: name of file installer (download from NVIDIA).
> 
> PATH_TO_PRIVATE_KEY: full path to private key. If you place in home folder, use /home/USER_NAME/ instead '~'
> 
> PATH_TO_PUBLIC_KEY: full path to public key. If you place in home folder, use /home/USER_NAME/ instead '~'
> 
> Example:
> 
> `sudo sh ./NVIDIA-Linux-x86_64-390.67.run -s --module-signing-secret-key=/home/itpropmn07/Nvidia.key --module-signing-public-key=/home/itpropmn07/Nvidia.der`
> 
> --> Done
> Read more https://us.download.nvidia.com/XFree86/Linux-x86/319.32/README/installdriver.html
