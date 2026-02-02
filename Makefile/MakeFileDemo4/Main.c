#include<stdio.h>
#include"Marvellous.h"

int main()
{
    int Ans = 0;
    Ans =  Addition(10,11);
    printf("Addition is : %d\n",Ans);
    

    return 0;
}

// gcc Main.c Helper.c -o app  == $(CC) Main.c Helper.c -o app-->./app
// 