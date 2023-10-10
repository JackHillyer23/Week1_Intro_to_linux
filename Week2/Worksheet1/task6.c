#include <stdio.h>

int main()
{
    int num1;
    char sign[3] = "odd";
    printf("Enter a number\n");
    scanf ("%d", &num1);

    if (num1%2 == 0)
    {
        printf("even\n");
    }
    else
        printf ("odd\n");
    return 0;
}