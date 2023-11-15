#!/bin/bash
rm -r ./tmp
link=$(realpath ./tmp)

ln -s $link ./tmp1 -f
ls -li . --color=auto

mkdir ./tmp

ls -li . --color=auto



bash ../ex3/gen.sh 10

cp ex1.txt ./tmp/

ls ./tmp

ln -s -f $link ./tmp1/tmp2

bash ../ex3/gen.sh 10

mv ex1.txt ./tmp1/tmp2

ls tmp1/tmp2/tmp2/tmp2


rm -r tmp

ls -li . --color=auto


rm tmp1

ls .
