#include <stdio.h>

int int_compare_f(void *, void *);

void * l_search(void *key, void *base, int n, int elemSize, int (*cmp_f)(void *, void *))
{
	int i;
	void *elemAddr;

	for(i=0; i<n; i++) {
		elemAddr = (char *)base + i * elemSize;
		if(cmp_f(key, elemAddr)==0)
			return elemAddr;
	}
	return '\0';
}

int int_compare_f(void *elem1, void *elem2)
{
	int *ip1 = elem1;
	int *ip2 = elem2;

	return *ip1 - *ip2;
}


void main(void)
{
	int array[] = {4, 3, 2, 6, 7 , 5, 44};
	int size = 7;
	int number = 5;

	int *found;

	found = l_search(&number, array, size, sizeof(int), int_compare_f);

	printf("%p->%d\n", found, *found);
}
