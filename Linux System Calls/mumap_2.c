// Faster than brk
#include<stdio.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{

    int fd = 0;

    char *ptr = NULL;

    struct stat st;

    fd = open("pune.txt",O_RDWR | O_CREAT,0777);

    ftruncate(fd,4096);

    fstat(fd,&st);

    ptr = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, fd, 0);

    strcpy(ptr,"Jay Ganesh...\n");

    printf("Data from mapped memory is : %s",ptr);

    munmap(ptr,4096);

    close(fd);

    return 0;
}