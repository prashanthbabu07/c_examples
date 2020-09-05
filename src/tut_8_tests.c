#include <stdio.h>

void main(void)
{
	int array[] = {0,1,2,3,4} ;
	int* pointer = array;
	
	if (sizeof array == sizeof pointer)
		printf("This will never be printed !!");
	
	if (sizeof(int*) == sizeof &array[0])
		printf("This will be printed !!\n");
	
	if (&array[2] - &array[0] == 8)
		printf("This will never be printed either, result is 2 not 8!!");
}
