#include <stdio.h>


void main(void)
{
	int a;
	short b;
	char c[3];
	int d[3];

	//memory allocaton in stack happens to be in order of bytes i.e. &b < &c < &a < &d
	printf("address of a = %p\n", &a);
	printf("address of b = %p\n", &b);
	printf("address of c = %p\n", &c);
	printf("address of d = %p\n", &d);

	int e;
	printf("address of e = %p\n", &e);

	printf("size of c = %zu\n", sizeof(c));

	a = 124; //a gets corrupted by the below code...

	for(b=0; b<=8; b++) {
		c[b] = 'a' + b;
	}

	printf("a = %d, c = %s\n", a, c);
}
