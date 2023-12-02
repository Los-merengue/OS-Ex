#!/bin/bash

fallocate --length 64MB lofs.img

LOOP_DEVICE=`sudo losetup -fP --show lofs.img`

mkfs -t ext4 lofs.img

mkdir -p lofsdisk


sudo mount -t ext4 $LOOP_DEVICE lofsdisk
