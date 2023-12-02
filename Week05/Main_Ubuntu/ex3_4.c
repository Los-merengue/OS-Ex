#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int balance = 1000; // Initial account balance

// Function to simulate a withdrawal
void *withdrawal(void *arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        int amount = 500;           // Amount to withdraw
        int temp_balance = balance; // Read the current balance
        temp_balance -= amount;     // Update the balance
        balance = temp_balance;     // Store the updated balance back
    }
    printf("Withdrawal thread: New balance after withdrawal: %d\n", balance);
    return NULL;
}

// Function to simulate a deposit
void *deposit(void *arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        int amount = 500;           // Amount to deposit
        int temp_balance = balance; // Read the current balance
        temp_balance += amount;     // Update the balance
        balance = temp_balance;     // Store the updated balance back
    }
    printf("Deposit thread: New balance after deposit: %d\n", balance);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // Create the withdrawal thread
    pthread_create(&thread1, NULL, withdrawal, NULL);

    // ex 4: // Wait for both threads to finish
    // pthread_join(thread1, NULL);

    // Create the deposit thread
    pthread_create(&thread2, NULL, deposit, NULL);

    sleep(0.5);

    // ex 4: // Wait for both threads to finish
    // pthread_join(thread2, NULL);

    // ex 3: Balance should stay the same as we did the same number
    //       of deposit and withdrawls
    printf("Final balance: %d\n", balance);

    return 0;
}