#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define SIZE_BUFFER 100

int main()
{
    int iRet = 0;
    int fd = 0;
    char Buffer[SIZE_BUFFER];

    memset(Buffer,'\0',SIZE_BUFFER);

    fd = open("Hole.txt",O_WRONLY | O_CREAT); 

    if (fd < 0)
    {
        printf("Unable to open file \n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully opened with the fd : %d\n",fd);

    iRet = lseek(fd,4100,SEEK_SET);

    printf("current file offset is : %d\n",iRet);

    iRet = write(fd,"END",3);

    printf("%d bytes gets written successfully\n",iRet);

    close(fd);
    

    return 0;
}