#include <stdio.h>

void main(void)
{
	printf("Size of\n");
	printf("int = %zu\n", sizeof(int));
	printf("char = %zu\n", sizeof(char));
	printf("float = %zu\n", sizeof(float));
	printf("double = %zu\n", sizeof(double));
	printf("char * = %zu\n", sizeof(char *));
}
