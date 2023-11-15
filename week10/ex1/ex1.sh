#!/bin/bash

echo "/dev folder"
ls -l /dev

echo "/etc folder"
ls -l /etc

ls -l /etc | grep ^d | wc -l

echo "int printf(char*, ...);int main(){printf(\"Hello world!\n\");}" > ex1.c

rm -f ex1 && gcc ex1.c -o ex1 && ./ex1

file ex1.c
file ex1

echo "int printf(char*, ...);int main(){printf(\"Привет, мир!\n\");}" > ex1.c

file ex1.c
file ex1
