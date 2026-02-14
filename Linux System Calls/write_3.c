#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0;
    
    char Buffer[] = "Indiaismycountry";

    int iRet = 0;

    fd = open("Demo.txt",O_WRONLY | O_APPEND);

    if(fd < 0)
    {
        printf("Unable to open file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd : %d\n",fd);

    iRet = write(fd,Buffer,16);     //Overwrite Issue

    printf("%d bytes gets successfully added \n",iRet);

    close(fd);

        
    return 0;
}