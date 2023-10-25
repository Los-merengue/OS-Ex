#!/bin/bash


gcc ex1.c -o ex1 && ./ex1 > output.txt &
pid=$!
echo $pid
kill -s SIGTERM $pid
# kill $pid
# default signal for kill is SIGTERM

kill -0 $pid
r=$?


if [ $r -ne 0 ];then
	kill -s SIGKILL $pid
fi