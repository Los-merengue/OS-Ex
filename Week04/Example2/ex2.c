#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

int main(){

pid_t r = fork();
if (r<0){
	perror("Cannot fork a new process!");
	return EXIT_FAILURE;
}

if (r!=0){ // parent
printf("Hello from process %d whose parent is %d\n", getpid(), getppid());

exit(EXIT_SUCCESS);

}else{ // child
sleep(5);
printf("Hello from process %d whose parent is %d\n", getpid(), getppid());
printf("child.id=%d\n", getpid());
printf("child.new.parent.id=%d\n", getppid());

}
// When the parent is terminated without waiting for its children
// the child processes will be orphand and will be assigned to the 
// first process (pid=1) init or systemd (depends on kernel implementation).




return EXIT_SUCCESS;
}