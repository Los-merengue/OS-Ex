#!/bin/bash

path="../ex1/ex1"

ls -i  $path

stat -c "It has %s bytes divided into %b blocks where each block has %B bytes" $path
stat -c "File permissions are %A" $path

cp ../ex1/ex1 ex2

stat -c "%h" ex2 # It is one because they have different i-node numbers


ls -i $path
ls -i ex2


stat -c "%h - %n - %i" /etc/* | grep ^3 # it represents the number of hard links to the same i-node
