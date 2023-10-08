#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *increment(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        counter++;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadA, threadB;

    // Create Thread A
    pthread_create(&threadA, NULL, increment, NULL);

    // Create Thread B
    pthread_create(&threadB, NULL, increment, NULL);

    // Wait for Thread A to finish
    pthread_join(threadA, NULL);

    // Wait for Thread B to finish
    pthread_join(threadB, NULL);

    printf("Counter value: %d\n", counter);

    return 0;
}

/*
In this example, Thread A and Thread B increment the counter variable 
simultaneously in their respective loops. Without any synchronization, a 
race condition occurs, and the final value of counter is unpredictable.

To solve this problem using thread joins, we use pthread_join to ensure that 
Thread A and Thread B complete their work before proceeding to print the final 
counter value. By joining the threads, we enforce a sequential execution order:

pthread_join(threadA, NULL); waits for Thread A to finish before allowing the 
main thread to continue.

pthread_join(threadB, NULL); waits for Thread B to finish before allowing the 
main thread to continue.

By the time the program reaches the printf statement, both threads have 
completed their work, and the counter value is guaranteed to be the sum of 
the increments from both threads.

Thread joins are an effective way to synchronize threads and ensure that a 
critical section of code is executed by only one thread at a time, preventing 
race conditions and producing reliable results.
*/
