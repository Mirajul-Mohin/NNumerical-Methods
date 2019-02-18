#include<stdio.h>

int main()
{
    int n;
    printf("Choose an option:\n");
    printf(" 1. A+ \n 2. A \n 3. A- \n 4. B+ \n");

    scanf("%d", &n);

    if(n==1)
    {
        printf("80-100\n");
    }

    else if(n==2)
    {
        printf("75-79\n");
    }

    else if(n==3)
    {
        printf("70-74\n");
    }

    else if(n==4)
    {
        printf("65-69\n");
    }

    else
        printf("You have selected wrong option\n");
}
