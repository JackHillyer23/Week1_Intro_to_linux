#include <stdio.h>

void printArray(int a[][3], int rows, char when) {
    switch (when) {
        case 'B':
            printf("Values in array before change:\n"); break;

        case 'A':
            printf("Values in array after change:\n"); break;

        default: 
            printf("Invalid option\n");
            return;
    }


    for (int i = 0; i < rows-1; ++i) {
        for (int j = 0; j<3; j++){
            printf("%d, ", a[i][j]);
        }
        printf("\n");
        
    }
}

void changeColumn(int a[][3], int colIndex, int row, int newValue) {
    
    a[colIndex][row] = newValue;
}

int main() {
    int array1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };


    printArray(array1, 3, 'B');
    changeColumn(array1, 1, 2, 64);
    changeColumn(array1, 0, 0, 2);
    changeColumn(array1, 1, 1, 9);
    printArray(array1, 3, 'A');

    return 0;
}