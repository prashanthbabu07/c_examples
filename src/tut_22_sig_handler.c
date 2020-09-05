#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

void print(int y)
{
	printf("you can't kill me :-)\n");
	printf("to kill me use kill -9 <process-id>\n");
}

void main(void)
{
	struct sigaction act, oact;
	act.sa_handler = print;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	printf("pressing Ctrl+C will not kill this program...\n");
	sigaction(SIGINT, &act, NULL);
	while(1);
	printf("Yeah...");
	exit(0);
}
