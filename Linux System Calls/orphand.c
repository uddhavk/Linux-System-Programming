#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{

    __pid_t pid = 0;

    fork();

    if(pid == 0)
    {
        printf("Child process is running...\n");
        printf("PID of child is %d : & PPID of child is : %d\n",getpid(),getppid());
    }
    else
    {
        printf("Parent process is running...\n");
        printf("PID of child is %d : & PPID of child is : %d\n",getpid(),getppid());
    }
}