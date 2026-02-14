#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Pid of current process is : %d\n",getpid());
    printf("Pid of parent process is : %d\n",getppid());

    return 0;
}