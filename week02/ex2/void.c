// C program to demonstrate
// use of void pointers
#include <stdio.h>

int main()
{
	int val = 30;
	void* ptr = &val;
	printf("%d", *(int*)ptr);
	return 0;
}
