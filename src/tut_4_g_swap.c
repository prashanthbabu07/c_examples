//This is generic swap function

#include <stdio.h>
#include <string.h>

void swap_print(void *vp1, void *vp2)
{
}
void swap(void *vp1, void *vp2, int size)
{
	char buffer[size];
	memcpy(buffer, vp1, size);
	memcpy(vp1, vp2, size);
	memcpy(vp2, buffer, size);
}

void main()
{
	int a = 10, b = 20;
	char *husband = strdup("Prasha");
	char *wife = strdup("Rekha");

	printf("before swap -> a=%d, b=%d\n", a, b);
	swap(&a, &b, sizeof(int));
	printf("after swap -> a=%d, b=%d\n", a, b); 

	printf("before swap -> husband=%s-%p, wife=%s-%p\n", husband, husband, wife, wife);
	swap(&husband, &wife, sizeof(char *));
	printf("after swap -> husband=%s-%p, wife=%s-%p\n", husband, husband, wife, wife);
}
