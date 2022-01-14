#include <stdio.h>
#include <conio.h>

int main(){
    const float pi = 3.14;
    float radius, area;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = pi * radius * radius;

    printf("The area of the circle is %f", area);

    return 0;
}

