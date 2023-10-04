#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threadFunction(void *arg)
{
    pthread_t tid = pthread_self(); // Get the thread ID

    // Print the message containing the thread ID
    printf("Thread ID: %lu\n", tid);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;

    // Create the first thread
    pthread_create(&thread1, NULL, threadFunction, NULL);

    // Create the second thread
    pthread_create(&thread2, NULL, threadFunction, NULL);

    // Wait for both threads to finish
    sleep(1);

    printf("Both threads have terminated.\n");

    return 0;
}