#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Global bank account balance
int balance = 1000;

// Function to be executed by the withdrawal thread
void *withdraw(void *arg) {
    int amount = 500;
    // Simulate some processing time
    usleep(100000);
    // Withdraw money
    balance -= amount;
    printf("Withdrawal: $%d\n", amount);
    pthread_exit(NULL);
}

// Function to be executed by the deposit thread
void *deposit(void *arg) {
    int amount = 300;
    // Simulate some processing time
    usleep(100000);
    // Deposit money
    balance += amount;
    printf("Deposit: $%d\n", amount);
    pthread_exit(NULL);
}

int main() {
    pthread_t withdrawal_thread, deposit_thread;

    // Create the withdrawal and deposit threads
    if (pthread_create(&withdrawal_thread, NULL, withdraw, NULL) != 0) {
        perror("Error creating withdrawal thread");
        return 1;
    }
    if (pthread_create(&deposit_thread, NULL, deposit, NULL) != 0) {
        perror("Error creating deposit thread");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(withdrawal_thread, NULL);
    pthread_join(deposit_thread, NULL);

    // Print the final balance
    printf("Final Balance: $%d\n", balance);

    return 0;
}


/* 
In this program, we have a global variable balance representing a bank 
account balance. Two threads, one for withdrawal and one for deposit, are 
created. Both threads attempt to update the balance variable without proper 
synchronization, leading to a race condition.

The critical region in this code is the point where the balance variable is 
updated. In the withdraw function, we subtract an amount from balance, and in 
the deposit function, we add an amount to balance. Since both threads can run 
concurrently, there is no guarantee of the order in which these operations 
occur.

A race condition occurs when both threads access the balance variable 
simultaneously, and the outcome depends on the order of execution and timing. 
This can lead to incorrect results, such as a negative balance or incorrect 
final balance.

Proper synchronization mechanisms, such as mutex locks or semaphores, should 
be used to protect the critical region (the balance variable) and ensure that 
only one thread can access it at a time, preventing race conditions.
*/
