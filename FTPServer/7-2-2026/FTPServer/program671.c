// Client Code
// 1.Creation of Socket
// 2.connect with server

// execute program669.c(server) first then program671.c (client)

#include<stdio.h>           // printf, scanf
#include<stdlib.h>          // malloc, free
#include<string.h>          // memset, memcpy

#include<unistd.h>          // close, write, read
#include<fcntl.h>           // create, link

#include<sys/socket.h>      // socket, bind, listen, accept, connect
#include<netinet/in.h>      // sockaddr_in, htons

#include<arpa/inet.h>       // inet_pton

int main()
{
    int ServerSocketFd = 0;
    int iRet = 0;
    int Port = 11000;

    struct sockaddr_in ServerAddr;

    // Step 1 : Create TCP socket

    ServerSocketFd = socket(AF_INET, SOCK_STREAM, 0);

    if(ServerSocketFd < 0)
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("socket gets created successfully with fd : %d\n",ServerSocketFd);

    // Step 2 : Connect with Server 

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    
    //127.0.0.1 (string) --> Binary Form
    inet_pton(AF_INET, "127.0.0.1", &ServerAddr.sin_addr);

    iRet = connect(ServerSocketFd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Unable to connect with server\n");
        return -1;
    }

    printf("Client Successfully connect with server\n");
    

    return 0;
}