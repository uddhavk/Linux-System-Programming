#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>


int main()
{
   
    int ret = 0;

    ret = nice(0);

    printf("Current nice value : %d\n",ret);

    ret = nice(-5);     // Increased Priority

    printf("Current nice value : %d\n",ret);

    if(ret == -1)
    {
        printf("%s\ns",strerror(errno));
    }

    
    return 0;
}