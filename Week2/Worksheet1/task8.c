#include <stdio.h>

int main ()
{
    int num1;
    
    printf("Enter a number: ");
    scanf ("%d", &num1);

    if (num1 ==0 || num1 == 1)
    {
        printf("The factorial is 1\n");
    } else 
    {
        int total = 1;
        int i = 1;
        for (i=1; i<num1+1; i++)
        {
            total = total*i;
        }
        printf("The factorial is %d\n",total);
    }

}