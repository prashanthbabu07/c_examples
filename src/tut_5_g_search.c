#include <stdio.h>

void* l_search(void *key, void *base, int n, int elemSize)
{
	int i;
	void *elemAddr;

	for(i=0; i<n; i++) {
		elemAddr = (char *)base + i * elemSize;
		if(memcmp(key, elemAddr, elemSize)==0)
			return elemAddr;
	}
	return '\0';
}


void main(void)
{

}
