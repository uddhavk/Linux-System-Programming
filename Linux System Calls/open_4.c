// if the file is present wiht the data (O_TRUNC) will delete the existing data

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


    return 0;
}