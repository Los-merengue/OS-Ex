#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "errno.h"
#include "signal.h"


int main(){

int n = 4;
pid_t parent = getpid();
pid_t r = fork();
// On success, the PID of the child process is returned in the parent, and
// 0  is returned in the child.  On failure, -1 is returned in the parent,
// no child process is created, and errno is set appropriately.

// failure of fork execution
if (r<0) return EXIT_FAILURE;

printf("Hello from [%d, %d - %d - %p]\n", r, getpid(), n, &n);

if (parent==getpid()){ //parent (r==0)
	printf("Hello from parent %d\n", getpid());
	sleep(1); // wait a little (printing some messages from child)
	kill(r, SIGKILL);
	printf("\nchild process %d is killed by the parent %d using SIGKILL signal\n", r, getpid());

}else{//child
	// infinite loop
	while(1){
		printf("Hello from child %d\n", getpid());
	}
}

return EXIT_SUCCESS;
}