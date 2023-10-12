#include <stdio.h>

int main()
{

    float length;
    float width;
    printf("This program calculates the area of a rectangle\n");

    printf ("Enter the Length of the rectangle \n");
    scanf("%f",&length);
    printf ("Enter the Width of the rectangle \n");
    scanf("%f",&width);

    float area=length*width;
    printf("The area of the rectangle you inputted is %f\n",area);

    return 0;
}