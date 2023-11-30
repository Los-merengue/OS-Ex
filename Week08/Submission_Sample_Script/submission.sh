#!/bin/bash


gcc ex1.c -o ex1


# Change the Permission of the Script
chmod +x hack.sh


# Run the Program
./ex1 &


# Run the script
./hack.sh


# Clear
rm ex1.c && rm hack.sh && rm ex1


#Create a new script 

echo "" > ex1.c && echo "" > hack.sh


