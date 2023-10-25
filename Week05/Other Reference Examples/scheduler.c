#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#define PS_MAX 10


typedef struct{
	int idx;
	int at, bt, rt, wt, ct, tat;
	int burst; // remaining burst
} ProcessData;

// the idx of the running process
int running_process = -1;

// the total time of the timer
unsigned total_time;

// data of the processes
ProcessData data[PS_MAX];

// array of all process pids
pid_t ps[PS_MAX];

// size of data array
unsigned data_size;

void read_file(FILE* file){

    // TODO: extract the data of processes from the {file} 
    // and store them in the array {data}
    // initialize ps array to zeros (the process is not created or terminated)

}

// send signal SIGCONT to the worker process
void resume(pid_t process) {
    // TODO: send signal SIGCONT to the worker process if it is not in one of the states
    // (1.not created or 2.terminated)
}

// send signal SIGTSTP to the worker process
void suspend(pid_t process) {
    // TODO: send signal SIGTSTP to the worker process if it is not in one of the states
    // (1.not created or 2.terminated)
}

// send signal SIGTERM to the worker process
void terminate(pid_t process) {
    // TODO: send signal SIGTERM to the worker process if it is not in one of the states
    // (1.not created or 2.terminated)
}

void create_process(int new_process) {

    // TODO: stop the running process

    // TODO: fork a new process and add it to ps array

    // TODO: Now the idx of the running process is new_process 

    // TODO: The scheduler process runs the program "./worker {new_process}" 
    // using one of the exec functions like execvp

}

ProcessData find_next_process() {

    // location of next process in {data} array
	unsigned location = 0;

	for(int i=0; i < data_size; i++) {

        // TODO: find location of the next process to run from the {data} array
        // Considering the scheduling algorithm FCFS

	}



	// if next_process did not arrive so far, 
    // then we recursively call this function after incrementing total_time
	if(data[location].at > total_time){
        // increment the time
        total_time++; 
        printf("Scheduler: Runtime: %u seconds.\nProcess %d: has not arrived yet.\n", total_time, location);
        return find_next_process(); 
	}

    // return the data of next process
	return data[location];
}


// reports the metrics and simulation results
void report(){
	printf("Simulation results.....\n");
	int sum_wt = 0;
	int sum_tat = 0;
	for (int i=0; i< data_size; i++){
		printf("process %d: \n", i);
		printf("	at=%d\n", data[i].at);
		printf("	bt=%d\n", data[i].bt);
		printf("	ct=%d\n", data[i].ct);
		printf("	wt=%d\n", data[i].wt);
		printf("	tat=%d\n", data[i].tat);
		printf("	rt=%d\n", data[i].rt);
		sum_wt += data[i].wt;
		sum_tat += data[i].tat;
	}

	printf("data size = %d\n", data_size);
	float avg_wt = (float)sum_wt/data_size;
	float avg_tat = (float)sum_tat/data_size;
	printf("Average results for this run:\n");
	printf("	avg_wt=%f\n", avg_wt);
	printf("	avg_tat=%f\n", avg_tat);
}

void check_burst(){

	for(int i = 0; i < data_size; i++)
		if (data[i].burst > 0)
		    return;

    // report simulation results
    report();

    // terminate the scheduler :)
	exit(EXIT_SUCCESS);
}


// This function is called every one second as handler for SIGALRM signal
void schedule_handler(int signum) {
    // increment the total time
    total_time++;



    /* TODO 
    1. If there is a worker process running, then decrement its remaining burst
    and print messages as follows:
    "Scheduler: Runtime: {total_time} seconds"
    "Process {running_process} is running with {data[running_process].burst} seconds left"
    
    1.A. If the worker process finished its burst time, then the scheduler should terminate 
    the running process and prints the message:
    "Scheduler: Terminating Process {running_process} (Remaining Time: {data[running_process].burst})"
    
    then the scheduler waits for its termination and there will be no running processes anymore.
    Since the process is terminated, we can calculate the metrics {ct, tat, wt}
    
    2. After that, we need to find the next process to run {next_process}. 
    3. If {next_process} is not running, then we need to check the current process
    3.A. If the current process is running, then we should stop the current running process
    and print the message:
    "Scheduler: Suspending Process {running_process} (Remaining Time: {data[running_process].burst})"
    3.B. set current process as the running process.
    3.C.1. then create a new process for {running_process} and print the message:
    "Scheduler: Starting Process {running_process} (Remaining Time: {data[running_process].burst})"
    Here we have the first response to the process {running_process} and we can calculate the metric {rt}
    3.C.2. or resume the process {running_process} if it is stopped and print the message:
    "Scheduler: Resuming Process {running_process} (Remaining Time: {data[running_process].burst})"
    */

}


int main(int argc, char *argv[]) {

    // read the data file
    FILE *in_file  = fopen(argv[1], "r");
  	if (in_file == NULL) {   
		printf("File is not found or cannot open it!\n"); 
  		exit(EXIT_FAILURE);
    } else {
        read_file(in_file);  
    }

    // set a timer
    struct itimerval timer;

    // the timer goes off 1 second after reset
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;

    // timer increments 1 second at a time
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    // this counts down and sends SIGALRM to the scheduler process after expiration.
    setitimer(ITIMER_REAL, &timer, NULL);

    // register the handler for SIGALRM signal
    signal(SIGALRM, schedule_handler);

    // Wait till all processes finish
    while(1); // infinite loop
}