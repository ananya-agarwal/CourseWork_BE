#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
 
int main()
{
   //define variables
    char str[100];
    int listen_fd, comm_fd, len;
    struct sockaddr_in servaddr,cli;
   
   
   //create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 //erases the data in the memory starting at the location pointed to by servaddr
    bzero( &servaddr, sizeof(servaddr));
 //create address
    servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(22000);
 //bind socket and address
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
 //listen on socket with max no of waiting connections = 10, non Blocking
    listen(listen_fd, 10);
    printf("\nServer is waiting for client to connect...........\n");
	
    //accepting a client request
     len = sizeof(cli);	
    comm_fd = accept(listen_fd, (struct sockaddr*)&cli, &len);
	
	//loop for sinding and recieving data
    while(1)
    {
         bzero( str, 100);  //erase content of str
 
        read(comm_fd,str,100);    //read data from socket comm_fd into str
 
        printf("Echoing back - %s",str); //print on server screen
 
        write(comm_fd, str, strlen(str)+1); //send back to client for echo
 
    }
}