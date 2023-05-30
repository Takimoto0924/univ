#include <stdio.h>
#include <math.h>

double f(double x, double a)
{
    double y = a*x*(1-x);
    return y;
}

int main(void)
{
    double a;
    scanf("%lf", &a);
    
    double x = 0.1;
    double y = f(x,a);

    while(fabs((y-x)/y)>=10e-12)
    {
        printf("%.16f %.16f\n", x, x);
        printf("%.16f %.16f\n", x, y);
        x = y;
        y = f(x,a);
    }
}