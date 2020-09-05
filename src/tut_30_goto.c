#include <stdlib.h>
#include <stdio.h>

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, x, y);
}

void main(void)
{
	system("clear");
	gotoxy(2, 20);
	printf("HELLO W O R L D\n");
}
