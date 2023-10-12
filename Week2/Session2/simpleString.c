#include <stdio.h>

int main(){
    char string1[5] = "Hello";
    int a;
    for (a = 4; a>=0; a--)
    {
        printf("%c ",string1[a]);
    }
    printf("\n");
    return 0;
}