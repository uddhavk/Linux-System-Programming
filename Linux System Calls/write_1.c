#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0;
    
    char Buffer[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int iRet = 0;

    fd = open("Demo.txt",O_WRONLY);

    if(fd < 0)
    {
        printf("Unable to open file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd : %d\n",fd);

    iRet = write(fd,Buffer,10);

    printf("%d bytes gets successfully added \n",iRet);

    close(fd);

        
    return 0;
}