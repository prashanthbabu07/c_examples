#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SIZE 128
#define NUM_CLIENT 3
#define PTHREAD_STACK_MIN 16384

void *connection_handler(void *socket_desc);

int main(int argc, char **args)
{
    int socket_desc , new_socket , c , *new_sock, i;
    pthread_t sniffer_thread;

    if(argc < 2) {
    	printf("Usage: ./cpchatterclient num_clients\n");
    	exit(0);
    }

    int num_clients = atoi(args[1]);

    pthread_attr_t attr;
	pthread_attr_init(&attr);

	int p_size = pthread_attr_setstacksize(&attr, PTHREAD_STACK_MIN * 2);

    for (i=1; i<=num_clients; i++) {
        if( pthread_create( &sniffer_thread , &attr ,  connection_handler , (void*) i) < 0)
        {
            perror("could not create thread");
            return 1;
        }
        //sleep(3);
    }
    pthread_exit(NULL);
    return 0;
}

void *connection_handler(void *threadid)
{
    int threadnum = (int)threadid;
    int sock_desc;
    struct sockaddr_in serv_addr;
    char sbuff[MAX_SIZE],rbuff[MAX_SIZE];

	if ((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Failed creating socket erro no - %d\n", sock_desc);

		pthread_exit(NULL);
		return 0;
	}

    bzero((char *) &serv_addr, sizeof (serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("10.42.0.94");
    serv_addr.sin_port = htons(12345);

    if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
        printf("Failed to connect to server\n");
    }

    int i;

    printf("Connected successfully client:%d\n", threadnum);
    while(1)
    {
        printf("For thread : %lu -> ", pthread_self());
        //fgets(sbuff, MAX_SIZE , stdin);

        for(i=0; i<MAX_SIZE-2; i++) {
        	sbuff[i] = 'A' + (random() % 26);
        }
        sbuff[MAX_SIZE-2] = '-';
        sbuff[MAX_SIZE-1] = '\0';

        write(sock_desc, sbuff, strlen(sbuff));
        //send(sock_desc,sbuff,strlen(sbuff),0);
        //puts("writting to socket done..");

        /*if(recv(sock_desc,rbuff,MAX_SIZE,0)==0)
            printf("Error");
        else
           fputs(rbuff,stdout);*/

        //sleep(2);

        i = read(sock_desc, rbuff, MAX_SIZE);
        //write(1, rbuff, i);
        printf("%s\n", rbuff);

        /*while ((i = read(sock_desc, rbuff, MAX_SIZE)) > 0)
        		write(1, rbuff, i);*/

        bzero(rbuff,MAX_SIZE);
        sleep(rand() % 2);
    }
    close(sock_desc);
    return 0;
}
