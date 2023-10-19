#include <stdio.h>
#include <math.h>



float volume(float radius){
    float answer;
    answer = (4/3)*(M_PI * radius * radius * radius);
    return answer;
}

int main(){
    float radius;
    float result;
    printf("Enter the radius of the sphere\n");
    scanf("%f",&radius);
    result = volume(radius);
    printf("The volume of this circle is %f\n",result);
}