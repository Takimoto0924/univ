#include <stdio.h>
#include <math.h>
#define D 4 

int main(void)
{
    //行列の定義
    double a[D][D] = {{2,4,1,-3},{-1,-2,2,4},{4,2,-3,5},{5,-4,-3,1}};
    double b[D] = {0,10,2,6};

    for(int k=0; k<=D-2; k++)
    {
        //部分ピボット選択
        int i_p = k;
        double a_p = fabs(a[k][k]);

        for(int i=k+1; i<=D-1; i++)
        {
            if(a_p < fabs(a[i][k]))
            {
                i_p = i;
                a_p = fabs(a[i][k]);
            }
        }

        if(i_p != k)
        {
            for(int j=k; j<=D-1; j++)
            {
                double t = a[k][j];
                a[k][j] = a[i_p][j];
                a[i_p][j] = t;
            }

            double s = b[k];
            b[k] = b[i_p];
            b[i_p] = s;
        }

        //階段行列の生成
        for(int i=k+1; i<=D-1; i++)
        {
            double alpha = -a[i][k]/a[k][k];

            for(int j=k+1; j<=D-1; j++)
            {
                a[i][j] = a[i][j] + alpha*a[k][j];
            }

            b[i] = b[i] + alpha*b[k];
        }
    }

    b[D-1]  = b[D-1]/a[D-1][D-1];

    //解の計算
    for(int k=D-2; k>=0; k--)
    {
        double tmp = b[k];

        for(int j=k+1; j<=D-1; j++)
        {
            tmp = tmp -a[k][j]*b[j];
        }

        b[k] = tmp/a[k][k];
    }

    //結果を出力
    for(int i=0; i<=D-1; i++)
    {
        printf("x[%d]=%lf\n", i, b[i]);
    }
}