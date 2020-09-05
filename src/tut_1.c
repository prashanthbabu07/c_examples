#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(void *value, void *number)
{
	printf("addr - %p value - %s\n", *(char **)value, *(char **)value);
	int **num = number;
	printf("addr - %p value - %d\n", *num, **num);
	int *num1 = (int *)number;
	printf("addr - %d\n", **(int **)number);
}

void main(void)
{
	int i;
	char ch;
	char *value;
	int *number;
	
	printf("address of i = %p\n", (void *)&i);
	printf("address of  ch = %p\n", (void *)&ch);
	
	i = 'A';

	printf("value of i = %d\n", i);
	value = strdup("Prashanth");
	number = malloc(sizeof(int));
	*number = 7;

	printf("addr of *value - %p\n", &value);
	printf("addr of value - %p\n", value);
	printf("contents of value - %s\n", value);

	printf("addr of *number - %p\n", &number);
        printf("addr of number - %p\n", number);
        printf("contents of *number - %d\n", *number);

	foo(&value, &number);
}
