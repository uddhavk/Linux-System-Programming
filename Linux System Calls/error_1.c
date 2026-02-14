#include<stdio.h>
#include<errno.h>

int main()
{
    printf("Demonstration of error\n");
    printf("%d\n",errno);
    return 0;
}