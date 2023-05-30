#include <stdio.h>

//被積分関数の定義
double f(double x)
{
    double y = 4/(1+x*x);
    return y;
}

int main(void)
{
    //分割数ｎ
    double n;
    scanf("%lf", &n);

    //面積の初期値を０に設定
    double sum = 0;

    //小台形の面積の和
    for(double i=1; i<n; i++)
    {
        double t = i/n;
        sum += f(t);
    }

    sum = (sum+(f(0)+f(1))/2)/n;

    //結果をターミナルに出力
    printf("%.16f\n", sum);
}