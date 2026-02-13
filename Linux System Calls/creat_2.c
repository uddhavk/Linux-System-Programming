#include<stdio.h>

int main(int argc,char *argv[])
{
    int fd = 0;

    fd = creat(argv,0777);

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