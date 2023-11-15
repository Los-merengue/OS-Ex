#!/bin/bash

bash gen.sh 10

ln ex1.txt ex11.txt -f
ln ex1.txt ex12.txt -f

diff ex1.txt ex11.txt
diff ex1.txt ex12.txt
echo "ex1.txt"
cat ex1.txt
echo "ex2.txt"
cat ex11.txt
echo "ex3.txt"
cat ex12.txt

ls -i ex1*.txt > output.txt

cat output.txt

du ex1.txt -h

ln ex1.txt /tmp/ex13.txt -f

find . -samefile ex1.txt
find / -samefile ex1.txt 2> /dev/null

stat -c "%h" ex1.txt

find / -samefile ex1.txt 2> /dev/null -exec rm {} \;
