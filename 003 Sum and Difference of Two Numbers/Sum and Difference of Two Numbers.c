#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b, sum_int, sub_int;
    float c, d, sum_float, sub_float;

    scanf("%d %d", &a,&b);
    scanf("%f %f", &c,&d);
    sum_int = a+b;
    sub_int = a-b;
    sum_float = c+d;
    sub_float = c-d;
    
    //to print float with n decimal places use %.nf (n = number of spaces)
    printf("%d %d \n%.1f %.1f",sum_int,sub_int,sum_float,sub_float);
    
    return 0;
}

