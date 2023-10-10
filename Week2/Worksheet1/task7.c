#include <stdio.h>

int main ()
{
    int num1;
    
    printf("Enter the degrees in fahrenheit: ");
    scanf ("%d", &num1);

    int celcius = (((num1-32)*5)/9);
    printf("This temperature is %d degrees celcius\n",celcius);
}