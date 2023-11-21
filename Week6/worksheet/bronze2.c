#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array1[2][3]={
        {1,2,3},
        {4,5,6}
    };
    int array2[3][2]={
        {1,2},
        {3,4},
        {5,6}
    };
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            printf("%d\n", array1[i][j]*array2[j][i]);
        }
    }
    

    return 0;
}