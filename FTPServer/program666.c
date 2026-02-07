// Server Code
// Creation of Socket
#include<stdio.h>
#include<sys/socket.h>

int main()
{
    int ServerSocket = 0;   //fd

    ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(ServerSocket < 0)
    {
        printf("Unable to create socket");
        return -1;
    }

    printf("Socket gets created successfully with fd : %d\n",ServerSocket);


    return 0;
}