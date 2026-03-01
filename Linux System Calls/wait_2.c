#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{

    pid_t pid = 0;
    pid_t x = 0;

    int status = 0;

    pid = fork();

    if(pid == 0)        // Child
    {
        sleep(10);
        exit(21);
    }

    x = wait(&status);

    printf("Child with PID %d get terminated with status %d\n",x,WEXITSTATUS(status));

    return 0;
}