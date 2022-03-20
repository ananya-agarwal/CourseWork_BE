//MULTIPLEXING TCP and UDP communication using Select


#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
//#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define PORT 5000
#define MAXLINE 1024

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int listenfd, connfd, udpfd, nready, maxfdp1;
    char buffer[MAXLINE];
    //pid_t childpid;
    fd_set rset;
    int len;
    struct sockaddr_in cliaddr, servaddr;
    char* message = "Hello Client";
//void sig_chld(int);
 
    /* create listening TCP socket */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	//servaddr.sin_addr.s_addr =inet_addr("192.168.0.2");
    servaddr.sin_port = htons(PORT);
 
    // binding server addr structure to listenfd
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, 10);
 
    /* create UDP socket */
    udpfd = socket(AF_INET, SOCK_DGRAM, 0);
    // binding server addr structure to udp sockfd
    bind(udpfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
     
    // clear the descriptor set
    FD_ZERO(&rset);
 
    // get maxfd
    maxfdp1 = max(listenfd, udpfd) + 1;
	 

    while(1) {            //for(;;) { 
        // set listenfd and udpfd in readset
        FD_SET(listenfd, &rset);
        FD_SET(udpfd, &rset);
        
        printf("%d",listenfd); //3 value mili iss new socket ko kyuki 0,1,2 are reserved 
         printf("\n.....Waiting for Client Requests.....\n");
        // select the ready descriptor
        nready = select(maxfdp1, &rset, NULL, NULL, NULL);
 
        // if tcp socket is readable then handle
        // it by accepting the connection
        if (FD_ISSET(listenfd, &rset)) {
            len = sizeof(cliaddr);
            connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len); //child c1 created
           // if ((childpid = fork()) == 0) { //fork() will make a copy of parent process
           //thus listenfd i.e. mastersocket ki ek copy is with connfd also now
                //close(listenfd);
                bzero(buffer, sizeof(buffer));
                printf("Message From TCP client: ");
                read(connfd, buffer, sizeof(buffer));
                puts(buffer);
                write(connfd, (const char*)message, sizeof(buffer));
                close(connfd);
               // exit(0);
            //}
            close(connfd);
        }
        // if udp socket is readable receive the message.
        if (FD_ISSET(udpfd, &rset)) {
            len = sizeof(cliaddr);
            bzero(buffer, sizeof(buffer));
            printf("\nMessage from UDP client: ");
            recvfrom(udpfd, buffer, sizeof(buffer), 0,
                        (struct sockaddr*)&cliaddr, &len);
            puts(buffer);
            sendto(udpfd, (const char*)message, sizeof(buffer), 0,
                (struct sockaddr*)&cliaddr, sizeof(cliaddr));
        }
    }
}
