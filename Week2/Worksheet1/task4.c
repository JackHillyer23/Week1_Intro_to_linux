#include <stdio.h>

int main()
{
    double pi = 3.141593;
    int radius;
    printf("Enter the radius of your circle\n");
    scanf ("%d", &radius);
    
    double area=radius*radius*pi;
    printf ("The area of the circle is %lf\n",area);
    return 0;
}