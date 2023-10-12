#include <stdio.h>

int main(){
    int array1 [5] = {13,44,99,23,61};
    int count;
    int total = 0;
    for (count = 0; count<5; count++)
    {
        total = total+array1[count];
    }
    printf("The total value in the array is %d\n",total);
    
    return 0;
}