#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd = open("second.c",O_CREAT | O_TRUNC,0777);

    if(fd == -1)
    {
        printf("unable to open file\n");
    }
    else
    {
        printf("File Successfully opened with fd : %d\n",fd);
    }

    close(fd);


    return 0;
}