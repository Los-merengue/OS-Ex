#!/bin/bash


ls /proc

# check status of process pid
cat /proc/{pid}/status

# maximum value for process id can be assigned by the kernel
# Tested on Ubuntu 23.04.03
cat /proc/sys/kernel/pid_max


# it is called systemd in moost Linux-distros
# System Management Daemon
# It is similar to init, systemd is the parent of all other
# processes directly or indirectly and is the first process
# that starts at boot hence typically assigned a "pid=1".

# Why replace init system with systemd?
# A init process starts serially i.e., one task starts only
# after the last task startup was successful and it was loaded
# in the memory. This often resulted into delayed and long booting time.
# However, systemd was not designed for speed but for getting the things
# done neatly which in turns avoid all the UN-necessary delay.
cat /proc/1/status



# Get ppid of the process systemd (init)
cat /proc/1/status | grep PPid
# 0 means that this process does not have a parent process