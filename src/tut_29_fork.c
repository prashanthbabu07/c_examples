#include <stdio.h>

void main(void)
{
	int a = 10, b = 20;

	a = fork();

	if(a==0)
		return;

	printf("%d - %d, %d\n", getpid(), a, b);

}
