// Client Application
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdbool.h>

/////////////////////////////////////////////////////////////
//
//  Command line Application
//  1st Argument : IP Address
//  2nd Argument : Port Number
//  3rt Argument : Target File Name
//  4th Argument : New File Name
//
//  ./client    127.0.0.1    9000      Demo.txt    A.txt
//   argv[0]     argv[1]     argv[2]   argv[3]    argv[4
//   argv[5]
//
/////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int Port = 0;                   // argv[2]
    int Sock = 0;
    int iRet = 0;

    char *ip = NULL;                // argv[1]
    char *Filename = NULL;          // argv[3]
    char *OutFileName = NULL;       // argv[4]
    
    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr; 

    
    

    if((argc < 5) || (argc > 5))
    {
        printf("Unable to procced as invalid number of argumnet\n");
        printf("Please provide below argument : \n");
        
        printf("1st Argument : IP Address\n");
        printf("2nd Argument : Port Number\n");
        printf("3rt Argument : Target File Name\n");
        printf("4th Argument : New File Name\n"); 

        return -1;
    }
    
    // Store Command line arguments into the Variable

    ip = argv[1];
    Port = atoi(argv[2]);
    Filename = argv[3];
    OutFileName = argv[4];

    ////////////////////////////////////////////////////////////
    // Step 1 : Create TCP socket
    ////////////////////////////////////////////////////////////

    Sock = socket(AF_INET, SOCK_STREAM, 0);

    if(Sock < 0)
    {
        printf("Unable to create the client socket\n");
        return -1;
    }

    ////////////////////////////////////////////////////////////
    // Step 2 : Connect with Server 
    ////////////////////////////////////////////////////////////

    memset(&ServerAddr, 0,sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    
    // Convert the IP address into the binary format

    inet_pton(AF_INET, ip, &ServerAddr.sin_addr);

    iRet = connect(Sock, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Unable to connect with server\n");

        close(Sock);

        return -1;
    }

    // Sending file name to server
    write(Sock,Filename,strlen(Filename));

    return 0;

}   // End of main