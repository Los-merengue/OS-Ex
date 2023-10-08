#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by the threads
void *threadStartRoutine(void *arg) {
    // Cast the argument to an integer to obtain the thread ID
    int threadID = *((int *)arg);

    // Print a message containing the thread ID
    printf("Thread %d is running.\n", threadID);

    // Sleep for a short time to simulate some work
    usleep(1000000); // Sleep for 1 second

    // Print a message indicating thread completion
    printf("Thread %d has completed.\n", threadID);

    // Terminate the thread
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int threadID1 = 1;
    int threadID2 = 2;

    // Create two threads
    if (pthread_create(&thread1, NULL, threadStartRoutine, &threadID1) != 0) {
        perror("Error creating thread 1");
        return 1;
    }
    if (pthread_create(&thread2, NULL, threadStartRoutine, &threadID2) != 0) {
        perror("Error creating thread 2");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have terminated.\n");

    return 0;
}


/* In this program:

We create two threads, thread1 and thread2, using pthread_create. 
Each thread is assigned a unique ID, which is passed as an argument to the 
thread's start routine function.
Inside the start routine function (threadStartRoutine), we print a message 
containing the thread ID to indicate that the thread is running. We then 
simulate some work using usleep (sleeping for 1 second) and print a completion
 message.
After the threads are created, we use pthread_join to wait for them to finish 
before proceeding.
Finally, we print a message to indicate that both threads have terminated.
*/