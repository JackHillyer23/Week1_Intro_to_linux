#include <stdio.h>

int main ()
{
    int balance;
    float rate;
    int years;
    printf("Enter the balance: ");
    scanf ("%d", &balance);
    printf("Enter the interest rate in percentage: ");
    scanf ("%f", &rate);
    printf("Enter how many years the interest is applied over: ");
    scanf ("%d", &years);

    float yearly = balance*(rate/100);
    int total = (yearly*years)+balance;
    printf("The return on the interest over %d years is %d\n",years,total);

}