#include <stdio.h>

void foo()
{
	int array [10];
	int i;

	for(i=0; i<10; i++) {
		array[i] = i;
		printf("%p->%d\n", &array[i], i);
	}
}

void bar()
{
	int array[10];
	int i;

	for(i=0; i<10; i++) {
		printf("%p->%d->%d\n", &array[i], i, array[i]);
	}
}


void main(void)
{
	foo();
	bar();
}
