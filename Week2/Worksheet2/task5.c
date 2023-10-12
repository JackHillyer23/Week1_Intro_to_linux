#include <stdio.h>

int main(){
    int array1 [6] = {99,44,99,61,61,44};
    int i;
    int j;
    for (i = 0; i<6; i++)
    {
        for (j = i+1; j<6; j++)
        {
            if (array1[i] == array1[j]){
                printf("%d is a duplicate\n", array1[i]);
            }
        }
    }
    
    return 0;
}