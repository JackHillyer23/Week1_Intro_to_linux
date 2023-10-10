#include <stdio.h>

int main ()
{
    int intsize = sizeof(int);
    int floatsize = sizeof(float);
    int doublesize = sizeof(double);
    int charsize = sizeof(char);

    printf("The typical size of an integer is %d\n",intsize);
    printf("The typical size of a float is %d\n",floatsize);
    printf("The typical size of a double is %d\n",doublesize);
    printf("The typical size of a character is %d\n",charsize);
}