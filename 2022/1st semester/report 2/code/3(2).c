#include <stdio.h>

double logistic_map(double x0, double a, int num, double delta,double r,double k) 
{
    double x = x0;
    for(double j=0; j<=num; j++) 
    {    
        double n = x*a*k/(delta*r);
        printf("%.16f %.16f\n", delta*j,n);
        x *= a*(1.0-x);
    }
}

int main(void)
{
    double r = 1;
    double k = 1;

    double n0[4] = {2.0, 1.5, 0.5, 0.1};

    for(double delta=0.5; delta >= 0.0625; delta=delta/2)
        {   
            printf("delta = %f\n",delta);
            double a = 1 + r*delta;

            for(int i = 0; i < 4; i++)
            {
                printf("n0 = %f\n",n0[i]);

                double x0 = n0[i]*r*delta/(k*a);

                logistic_map(x0,a,5/delta, delta, r, k);
                printf("\n");
            }
        }
    return 0;
}