#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 10000

int main(void)
{
    srand(time(NULL));
    double a[N];

    for(int i=0; i<N; i++)
    {
        //乱数0~1
        double u1 = (double)rand()/RAND_MAX;
        double u2 = (double)rand()/RAND_MAX;

        //条件を満たすような写像
        double x1 = sqrt(-0.5*log(u1))*cos(2.0*M_PI*u2);
        a[i] = x1;
    }

    //生成した乱数をバブルソート
    for(int i=0; i<=N-2; i++)
    {
        for(int j=N-1; j>=i+1; j--)
        {
            if(a[j-1]>a[j])
            {
                double b = a[j];
                a[j] = a[j-1];
                a[j-1] = b;
            }
        }
    }

    //結果を出力
    printf("%lf\n", a[228]);
    printf("%lf\n", a[5000]);
    printf("%lf\n", a[9772]);
}