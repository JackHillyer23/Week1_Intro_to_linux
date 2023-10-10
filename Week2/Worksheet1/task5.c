#include <stdio.h>

int main()
{
    float a=6;
    float b=2.7433;
    printf ("%f,%f\n",a,b);
    float temp;
    temp = a;
    a=b;
    b=temp;
    printf ("%f,%f\n",a,b);
    return 0;
}