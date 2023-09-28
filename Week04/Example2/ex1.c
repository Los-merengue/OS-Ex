#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"


int main(){

pid_t r = fork();
if (r<0){
	perror("Cannot fork a new process!");
	return EXIT_FAILURE;
}

if (r==0){ // child
printf("Hello from process %d whose parent is %d\n", getpid(), getppid());
exit(EXIT_SUCCESS);

}else{ // parent
sleep(5);
printf("Hello from process %d whose parent is %d\n", getpid(), getppid());

}
// When the child is terminated or stopped, a signal SIGCHLD
// is sent to the parent process by the kernel
// If the parent did not handle this signal, a zombie process will be created




return EXIT_SUCCESS;
}