#include <stdio.h>

int main ()
{
    float num1;
    
    printf("Enter the time in days the light has been travelling for: ");
    scanf ("%f", &num1);

    long double distance = (((num1*86400)*299792.458));
    printf("This light has travelled %Lf kilometres\n",distance);
}