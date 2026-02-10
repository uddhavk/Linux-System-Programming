// Argument line code
#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of command line argument are : %d\n",argc);

    printf("Executable name : %s\n",argv[0]);
    printf("IP Address : %s\n",argv[1]);
    printf("Poert number : %s\n",argv[2]);
    printf("Targgeted file : %s\n",argv[3]);
    printf("New file name : %s\n",argv[4]);

    return 0;
}