#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>

// 6 digits for big triangular numbers like 113050
#define TRI_BASE 1000000

// current process pid (which executed this program)
pid_t pid;

// current process idx (starts from 0)
int process_idx;

// next triangular number
long tris;

// is next triangular is found
bool found = false;

bool is_triangular(long n){
    for (long i = 1; i <= n; i++){
      if (i * (i + 1) == 2 * n){
         return true;
      }
   }
   return false;
}

void signal_handler(int signum){

    // print info if next triangular is found.
    if (found)
	    printf("Process %d (PID=<%d>): The next triangular found = \e[0;31m%ld\e[0m\n", process_idx, pid, tris);

	switch(signum) {
    // pause the process indefinitely
	case SIGTSTP:
	    printf("Process %d: stopping....\n", process_idx);
	    pause();
	    break;
	case SIGCONT:
	// continue the process
	    printf("Process %d: resuming....\n", process_idx);
	    break;
	case SIGTERM:
	// terminate the process
        printf("Process %d: terminating....\n", process_idx);
	    exit(EXIT_SUCCESS);
	    break;
	default:
	    break;
	}
}

// generates a big number n
long big_n() {
    time_t t;
    long n = 0;
    srand((unsigned) time(&t));
    while(n < TRI_BASE)
        n += rand();
    return n % TRI_BASE;
}

int main(int argc, char *argv[]){

    // TODO: generate a big random number using big_n function, 
    // and get the process_idx from argv
    // process idx
    process_idx = ....
    // big n
    tris = ....


    pid = getpid();


    // TODO: register the signals
    

    // The first message after creating the process    
    printf("Process %d (PID=<%d>): has been started\n", process_idx, pid); 
    printf("Process %d (PID=<%d>): will find the next trianguar number from (%ld, inf)\n", process_idx, pid, tris);
    long next_n = tris +1; 



    // TODO: search for next triangular number
    // After finding the number, set found to true


    // Wait till termination by the scheduler.
    pause();
    
}