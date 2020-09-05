#include <stdio.h>
#include <string.h>

void main()
{
	char *ch = "abcd";
	char carray[5] = "abcd";

	printf("addr ch - %p, addr carray - %p\n", &ch, &carray);
}
