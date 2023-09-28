#!/bin/bash

output=$(gcc ex2.c -o ex2 && ./ex2)
echo $output

pid=$(echo $output | grep "child.new.parent.id=[[:digit:]]*" -o | grep "[[:digit:]]*" -o)

id=$(echo $output | grep "child.id=[[:digit:]]*" -o | grep -o "[[:digit:]]*")

echo $id
echo $pid

cat /proc/$pid/status