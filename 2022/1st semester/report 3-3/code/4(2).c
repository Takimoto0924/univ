#include <stdio.h>

//関数の定義
double fx(double x, double y, double dt)
{
    double k1 = y;
    double k2 = 
    
}

double fy(double x, double y, double dt)
{
    return y = y - x*dt;
}

int main(void)
{
    //初期値を設定
    double x_0 = 1;
    double x = x_0;
    double y_0 = 1;
    double y = y_0;
    double t = 0;

    printf("%.2f %.16f %.16f\n", t, x, y);

    //時間刻み幅ごとの数値解
    for(double dt=0.16; dt>=0.01; dt/=4)
    {
        for(double t=dt; t<=10; t+=dt)
        {
            x = fx(x,y,dt);
            y = fy(x,y,dt);

            printf("%.2f %.16f %.16f\n" ,t, x, y);
        }
    }
}