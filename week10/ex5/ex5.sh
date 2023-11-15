#!/bin/bash
echo > ex5.txt

ls -l ex5.txt
chmod a-w ex5.txt
ls -l ex5.txt
chmod uo=rwx ex5.txt
ls -l ex5.txt


# 660
# rw-rw----

# 775
# rwxrwxr-x

# 777
# rwxrwxrwx
