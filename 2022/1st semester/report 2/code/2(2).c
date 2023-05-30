#include <stdio.h>
#include <math.h>

//実数関数f(x)の定義
double f(double x);

//f(x)の導関数の定義
double df(double x);

int main(void)
{
    //初期値x
    double x;
    scanf("%lf", &x);

    //ニュートン法の反復公式によって得られるx_
    double x_ = x - f(x)/df(x);

    //2数の差の絶対値が指定の値未満になるまでループ
    while(fabs((x_-x)/x_)>=10e-12)
    {
        //２数の値を更新
        x = x_;
        x_ -= f(x)/df(x);
    }

    //結果をターミナルに出力
    printf("%.16f\n",x_);
}