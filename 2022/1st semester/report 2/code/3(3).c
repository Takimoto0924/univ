#include <stdio.h>
#include <math.h>

double f(double x, double a)
{
    double y = a*a*a*x*x*x*x-2*a*a*a*x*x*x+(a*a*a+a*a)*x*x+(1-a*a)*x;
    return y;
}

double df(double x, double a)
{
    double y = 4*a*a*a*x*x*x-6*a*a*a*x*x+2*(a*a*a+a*a)*x+(1-a*a);
    return y;
}

int main(void)
{
    double a = 3.3;
    double x = 1;
    double x_ = x - f(x,a)/df(x,a);

    while(fabs((x_-x)/x_)>=10e-12)
    {
        x = x_;
        x_ = x - f(x,a)/df(x,a);
    }

    double x1 = x_;
    double x2 = a*x1*(1-x1);
    printf("%.16f %.16f\n",x1, x2);
}