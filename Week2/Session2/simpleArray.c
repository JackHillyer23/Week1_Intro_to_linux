#include <stdio.h>

int main(){
    int a [10];
    int count;
    for (count = 0; count<10; count++)
    {
        a[count] = count*10 + count;
    }
    printf("The first 2 elements are %d and %d respectivelly\n",a[0],a[1]);
    printf("Or, via pointers %d and %d\n",*a,*(a+1));
    
    return 0;
}