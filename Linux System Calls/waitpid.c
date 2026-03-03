#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    __pid_t childpid = 0;
    pid_t ret = 0;
    int status = 0;

    childpid = fork();

    if(childpid == 0)
    {    
        printf("Child is Running.with PID : %d \n",getpid());
        sleep(10);
        printf("Child process is Exiting...\n");
        exit(11);

    }
    else
    {
        printf("parent is Running...\n");
        
        printf("Parent is waititng for child : %d\n",childpid);

        ret = waitpid(-1,&status,0);

        if(WIFEXITED(status))
        {
            printf("Child exit with PID : %d\n",ret);
            printf("Exit status of child is : %d\n",WEXITSTATUS(status));
        }

    }
    
    return 0;
}