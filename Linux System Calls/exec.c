#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    if(pid == 0)
    {
        printf("Child Says : PID of current process : %d, PID of Parent : %d, Return value of fork : %d\n",getpid(), getppid(), pid);

        execl("./FirstExe","",NULL);
    }
    else
    {
        printf("Child Says : PID of current process : %d, PID of Parent : %d, Return value of fork : %d\n",getpid(), getppid(), pid);
     
    }


    return 0;
}