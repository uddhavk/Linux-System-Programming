#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{

    pid_t pid = 0;

    pid = fork();

    if(pid == 0)
    {
        sleep(10);
        printf("Child Process is Running\n");
    }
    else
    {
        printf("parent Process is Running\n");
    }
      


    return 0;
}