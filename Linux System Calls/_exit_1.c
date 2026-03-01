#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("process is created\n");


    _exit(11);
}