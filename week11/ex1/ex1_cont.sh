#Change ownership and create file for the file system

sudo chown $USER:$USER lofsdisk

cd lofsdisk
echo "Emeka" > file1
echo "Nzeopara" > file2

# Copy executables

cp --parents /usr/bin/{bash,cat,echo,ls} ./

#Copy dependencies

cp --parents /lib/x86_64-linux-gnu{libtinfo.so.6,lib1.so.2,libc.so.6,\
libpcre2-8.so.0,libpthread.so.0} ./

cp --parents /lib64/ld-linux-x86-64.so.2 ./

cd ..

gcc ex02.c -o ./lofsdisk/ex02.out -static -g -Wall -fsanitize=undefined \
-fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow

sudo chroot ./lofsdisk ./ex02.out > ex02.txt

./lofsdisk/ex02.out >> ex02.txt