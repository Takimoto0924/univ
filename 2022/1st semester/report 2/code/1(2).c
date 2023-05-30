#include <stdio.h>
#include <math.h>

double f(double x)
{
    double y = 4/(1+x*x);
    return y;
}

int main(void)
{
    double n[5] = {10,100,1000,10000,100000};

    for(int k=0; k<5; k++)
    {
        double sum = 0;

        for(double i=1; i<n[k]; i++)
        {
            double t = i/n[k];
            sum += f(t);
        }

        sum = (sum+(f(0)+f(1))/2)/n[k];

        printf("%.16f %.16f\n", sum, sum-M_PI);
    }
}