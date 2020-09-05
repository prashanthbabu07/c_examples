#include <stdio.h>
#include <string.h>

int int_compare_f(void *, void *);

void * l_search(void *key, void *base, int n, int elemSize, int (*cmp_f)(void *, void *))
{
	int i;
	void *elemAddr;

	for(i=0; i<n; i++) {
		elemAddr = (char *)base + i * elemSize;
		printf("%p\n", elemAddr);
		if(cmp_f(key, elemAddr)==0)
			return elemAddr;
	}
	return '\0';
}

int strcmp_f(void *elem1, void *elem2)
{
	char *ip1 = *(char **)elem1;
	char *ip2 = *(char **)elem2;
	
	printf("%p == %p == %p\n", elem1, elem2, *(char **)elem2);

	return strcmp(ip1, ip2);
}


void main(void)
{
	char *notes[] = {"ab", "ef", "jk", "lm", "ku"};
	int size = 5;
	char *fav = "jk";

	char **found;

	found = l_search(&fav, notes, size, sizeof(char *), strcmp_f);

	printf("%p->%s\n", found, *found);
	
	printf("%s\n", *(char **)notes);
}
