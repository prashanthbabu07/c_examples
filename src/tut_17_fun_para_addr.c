#include <stdio.h>

void foo(int a, int b)
{
	printf("foo() addr a->%p\tb->%p\n", &a, &b);
}


void main(void)
{
	int a, b;
	a = 100;
	b = 200;
	printf("main() addr a->%p\tb->%p\n", &a, &b);
	foo(a, b);
}
