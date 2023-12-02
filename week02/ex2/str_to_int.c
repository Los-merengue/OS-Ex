#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "2022"; // Input string
    int integerVal;

    // Use atoi to convert the string to an integer
    integerVal = atoi(str);

    printf("String: %s\n", str);
    printf("Integer: %d\n", integerVal);

    return 0;
}
