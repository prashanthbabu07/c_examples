#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <string.h>

void signal_handler(int sig)
{
	static count = 0;
	printf("signal occured %d\n", ++count);
}

void main(void)
{
	struct sigaction act, oact;
	struct itimerval it;

	//memset (&act, 0, sizeof (act));
	act.sa_handler = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGPROF, &act, NULL); //attachh single for signal handler.

	it.it_interval.tv_sec = 0;
	it.it_interval.tv_usec = 250000;
	it.it_value.tv_sec = 0;
	it.it_value.tv_usec = 250000;

	setitimer(ITIMER_PROF, &it, NULL); //generate singal at each intervals.
	
	while(1);
}
