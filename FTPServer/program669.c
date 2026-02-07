// Server Code
// 1.Creation of Socket
// 2.bind 
// 3.listen
#include<stdio.h>           // printf, scanf
#include<stdlib.h>          // malloc, free
#include<string.h>          // memset, memcpy

#include<unistd.h>          // close, write, read
#include<fcntl.h>           // create, link

#include<sys/socket.h>      // socket, bind, listen, accept, connect
#include<netinet/in.h>      // sockaddr_in, htons

/*
struct sockaddr
{
    sa_family_t sa_family;
    char sa_data[14];
}

*/

int main()
{
    int ServerSocket = 0;   //fd
    int iRet = 0;
    int Port = 11000;
    int ClientSocketFd = 0;  

    struct sockaddr_in ServerAddr; // structure object

    // Step 1 : Create TCP socket
    ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(ServerSocket < 0)
    {
        printf("Unable to create socket");
        return -1;
    }

    printf("Socket gets created successfully with fd : %d\n",ServerSocket);

    // Step 2 : Attach the socket to IP address and port number

    // Filling the structure
    memset(&ServerAddr, 0, sizeof(ServerAddr));  // Set values Structure to 0

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = INADDR_ANY;
    ServerAddr.sin_port = htons(Port);

    iRet = bind(ServerSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("bind system call fail\n");
        close(ServerSocket);
        return -1;
    }

    printf("bind operation with socket is successfully\n");

    // Step 3 : Mark the socket as a active socket

    // 11--> how many clients can be connected at a time
    iRet = listen(ServerSocket, 11);

    if(iRet == -1)
    {
        printf("Unable to convert socket in listen mode\n");
        return -1;
    }

    printf("Server is live at port %d\n",Port);

    // Step 4 : Accept new socket request

    
    ClientSocketFd = accept(ServerSocket, NULL, NULL);

    if(ClientSocketFd == -1)
    {
        printf("Unable to accept request from client \n");
        return -1;
    }


    printf("Request accepted by Server\n");

    return 0;
}