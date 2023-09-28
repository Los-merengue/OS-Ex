#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "errno.h"



int main(){

int n = 4;
pid_t parent = getpid();
pid_t r = fork();
// On success, the PID of the child process is returned in the parent, and
// 0  is returned in the child.  On failure, -1 is returned in the parent,
// no child process is created, and errno is set appropriately.

printf("Hello from [%d, %d - %d - %p]\n", r, getpid(), n, &n);
sleep(1);
if (parent==getpid()){ //parent
printf("Hello from parent %d\n", getpid());
exit(EXIT_SUCCESS);
}else{//child
printf("Hello from child %d\n", getpid());
exit(EXIT_FAILURE);
}

return EXIT_SUCCESS;
}