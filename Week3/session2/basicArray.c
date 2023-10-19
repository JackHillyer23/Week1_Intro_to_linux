#include <stdio.h>

int sum(int a, int b){
    int answer;
    answer = a + b;
    return answer;
}

int main(){
    int y =2;
    int z = sum(10,y);
    printf("10 + %d = %d\n",y,z);
}