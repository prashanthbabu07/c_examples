#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(void *base, int n, int elems)
{
	int front_size = sizeof(int)*elems;
	int end_size = sizeof(int)*(n-elems);
	printf("f-%d e-%d\n", front_size, end_size);
	char buffer[front_size];
	memcpy(buffer, base, front_size);
	memmove(base, (char *)base + front_size, end_size);
	memcpy((char *)base + end_size, buffer, front_size);
	
}

void print_array(int nums[], int n)
{
	int i;

        for(i=0; i<n; i++) {
                printf("%d -> %d\n", i, nums[i]);
        }
}

void main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = 9;

	printf("initial array\n");
	print_array(nums, n);

	rotate(&nums, n, 3);

	printf("after rotate\n");
	print_array(nums, n);

	rotate(&nums, n, 1);
	print_array(nums, n);
}
