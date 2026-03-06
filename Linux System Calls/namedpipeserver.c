// Named Pipe Server

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    int iRet = 0;

    iRet = mkfifo("/tmp/marvellous",0666);

    if(iRet == 0)
    {
        printf("named pipe  gets successfully created \n");
    }
    close(fd);



    return 0;
}