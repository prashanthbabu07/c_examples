#include <stdio.h>

void main()
{
	int array[3];
	int i;


	printf("%p\n", &i);
	//this runs forever... since the address space is being updated with overflow...
	for(i=3; i>=-1; i--) {
		array[i] = 3;
		printf("%d->%p\n", i, &array[i]);
	}
}
