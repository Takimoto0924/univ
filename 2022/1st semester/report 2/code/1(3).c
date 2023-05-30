#include <stdio.h>
#include <math.h>

//被積分関数の定義
double f(double x)
{
    double y = exp(-x*x/2)/sqrt(2*M_PI);
    return y;
}

int main(void)
{
    for(double w=1; w<=3; w++)
    {
        //分割数
        double n = 10000;
        
        //面積の初期値
        double sum = 0;

        //小台形の面積の和
        for(double i=1; i<n; i++)
        {
            double t = -w + 2*w*i/n;
            sum += f(t);
        }

        sum = 2*w*(sum+(f(-w)+f(w))/2)/n;

        //結果をターミナルに出力
        printf("%.16f\n", sum);
    }
}