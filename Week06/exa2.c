#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdbool.h"
#include "signal.h"
#include "ctype.h"


pid_t pid=0;

void handler(int signum){

switch (signum){

case SIGINT:
	printf("Interrupted!\n");
	signal(SIGINT, SIG_DFL);
	break;
case SIGALRM:
	printf("parent pid = %d\n", getpid());
	printf("child pid = %d\n", pid);
	printf("child is terminated..\n");
	kill(pid, SIGTERM);
	break;
case SIGUSR1:
	printf("negative number\n");
	break;
case SIGUSR2:
	printf("not a number\n");
	break;
default:
	break;
	}
}


int main(){
signal(SIGINT, handler);
signal(SIGALRM, handler);
alarm(3);

pid_t r = fork();
if (r<0) exit(EXIT_FAILURE);


if (r==0){
	while(true){
		printf("Hello from child!\n");
		sleep(1);
	}
}else{
	pid = r;
}

printf("pid=%d\n", pid);


signal(SIGUSR1, handler);
signal(SIGUSR2, handler);

char s[100];
if (scanf("%s", s)>0){

	if (s[0]=='-'){
		raise(SIGUSR1);
		// kill(getpid(), SIGUSR1);
	}else{
		int i=0;
		while(s[i]!='\0'){
			if (!isdigit(s[i]))
				kill(getpid(), SIGUSR2);
			i++;
		}
	}
}

while(true){
printf("Hello from parent!\n");
usleep(1000000);
}


return EXIT_SUCCESS;

}