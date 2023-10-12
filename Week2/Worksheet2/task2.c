#include <stdio.h>

int main(){
    int array1[5] = {25,6,72,59,8};
    int count;
    for (count = 4; count>=0; count--)
    {
        printf("%d, ",array1[count]);
    }
    printf("\n");
    return 0;
}