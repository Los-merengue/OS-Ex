#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("hello world!\n");
        usleep(1000000); // Sleep for 1 second
    }
    return 0;

}
