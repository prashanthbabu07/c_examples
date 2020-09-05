#include <stdio.h>

void foo(int);

void addition(int elem1, int elem2)
{
	int e1 = elem1;
	int e2 = elem2;

	foo(e1);
}

void foo(int a)
{
	int xyz = a;
}


void main()
{
	int a, b;
	printf("a-%p, b-%p\n", &a, &b);
	addition(a, b);
}
