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
        sleep(20);
        printf("PID of child is %d : & PPID of child is : %d\n",getpid(),getppid());
        exit(0);
    }
    else
    {
        printf("Parent process is running...\n");
        printf("PID of child is %d : & PPID of child is : %d\n",getpid(),getppid());
        exit(1);
    }

    return 0;
}