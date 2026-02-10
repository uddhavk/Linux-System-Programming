// Process subsystem
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

int main()
{
    pid_t pid = 0;

    pid = fork();

    if(pid < 0);
    {
        printf("Unable to create child process\n");
        return -1;
    }

    if(pid == 0)
    {
        printf("Child process gets created successfully\n");
    }
    
    return 0;
}