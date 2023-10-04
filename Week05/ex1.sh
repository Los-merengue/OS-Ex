#!/bin/bash

gcc ex1.c -o ex1

for i in {1..10}
do
    message="Message $i"
    echo "Running with message: $message"
    ./ex1 "$message"
    echo ""
done