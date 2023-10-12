#include <stdio.h>

int main(){
    int array1 [3] = {13,44,99};
    int array2 [3] = {55,8,90};
    int array3 [6];
    int count;
    for (count = 0; count<3; count++)
    {
        array3[count] = array1[count];
    }
    for (count = 0; count<3; count++)
    {
        array3[count+3] = array2[count];
    }
    for (count = 0; count<6; count++)
    {
        printf( "%d ",array3[count]);
    }
    
    printf("\n");
    return 0;
}