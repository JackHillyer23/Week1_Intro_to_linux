#include <stdio.h>

int main(){
    int array1 [5] = {13,44,99,23,61};
    int count;
    int temp;
    for (count = 4; count>-1; count--)
    {
        if (count == 4){
            temp = array1[count];
        }else if(count == 0){
            array1[count+1]=array1[count];
            array1[count]=temp;
        }else{
            array1[count+1]=array1[count];
        }
        
        
    }
    for (count = 0; count<5;count++){
        printf("%d, ",array1[count]);
    }
    
    printf("\n");
    return 0;
}