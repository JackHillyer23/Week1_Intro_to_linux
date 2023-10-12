#include <stdio.h>

int main(){
    int array1 [5] = {13,44,99,23,61};
    int count;
    int max = array1[0];
    for (count = 1; count<5; count++)
    {
        if (array1[count]>max){
            max = array1[count];
        }
    }
    printf("The largest value in the array is %d\n",max);
    
    return 0;
}