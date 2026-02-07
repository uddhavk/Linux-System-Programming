// Client Code
// 1.Creation of Socket

#include<stdio.h>           // printf, scanf
#include<stdlib.h>          // malloc, free
#include<string.h>          // memset, memcpy

#include<unistd.h>          // close, write, read
#include<fcntl.h>           // create, link

#include<sys/socket.h>      // socket, bind, listen, accept, connect
#include<netinet/in.h>      // sockaddr_in, htons

int main()
{
    int ServerSocketFd = 0;

    // Step 1 : Create TCP socket

    ServerSocketFd = socket(AF_INET, SOCK_STREAM, 0);

    if(ServerSocketFd < 0)
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("socket gets created successfully with fd : %d\n",ServerSocketFd);

    

    return 0;
}