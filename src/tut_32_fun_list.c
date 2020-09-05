#include <stdio.h>
#include <string.h>

void foo(int a, int b)
{
	printf("a=%p->%d, b=%p->%d b(*)=%p->%d\n", &a, a, &b, b, &b + 1, *(int *)&b + 1);
	void *temp = &b + 1;
	int c = -100;
	memcpy(temp, &c, sizeof(int));
	printf("a=%p->%d\n", &a, a);
}

void main(void)
{
	int a = 10, b = 20;
	foo(a, b);
}
