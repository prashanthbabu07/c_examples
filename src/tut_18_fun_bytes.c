#include <stdio.h>

void foo(int a, int *addr)
{
	int diff = &a - addr;
	printf("foo() addr a->%p\tb->%p\n", &a, addr);
	printf("compiler bytes info %d\n", diff);
}


void main(void)
{
	int a;
	int b;
	a = 100;
	b = 200;
	printf("main() addr a->%p\tb->%p\n", &a, &b);
	foo(a, &a);
}
