#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int fd[2], nbytes;
	pid_t childpid;
	char *string = "hello world\n";
	char readbuffer[80];

	pipe(fd);

	int i;

	/*for(i=0; i<2; i++) {
		printf("%d\n", fd[i]);
	}*/

	if((childpid = fork()) == -1) {
		perror("fork()\n");
		exit(0);
	}

	for(i=0; i<2; i++) {
                printf("%d\n", fd[i]);
        }

	if(childpid==0) {
		close(fd[0]);
		write(fd[1], string, (strlen(string)+1));
	}
	else {
		close(fd[1]);
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("received string: %s", readbuffer);
	}
}
