#include <stdio.h>

void swap(int *, int *);

void main(void)
{
	int a = 10, b = 20;

	printf("address a %p value = %d\t", &a, a);
    printf("address b %p value = %d\n", &b, b);

	swap(&a, &b);
	printf("address a %p value = %d\t", &a, a);
	printf("address b %p value = %d\n", &b, b);
}

void swap(int *ap, int *bp)
{
	int temp;
	temp = *ap;
	*ap = *bp;
	*bp = temp;
	printf("a=%d, b=%d\n", *ap, *bp);
}
