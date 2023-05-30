#include <stdio.h>
#include <math.h>
#define N 3

int main(void)
{
    //行列とベクトルの定義    
    double a[N][N] = {{0.1,0.3,0.5},{0.3,0.2,0.1},{0.6,0.5,0.4}};
    double y[N] = {1,0,0};
    double z[N];
    double z_z;
    double k;

    //
    for(int t=0; t<100; t++)
    {
        //行列とベクトルの積
        z_z = 0;
        for(int i=0; i<N; i++)
        {
            z[i] = 0;

            for(int j=0; j<N; j++)
            {
                z[i] += a[i][j]*y[j];
            }

            z_z += z[i]*z[i];
        }

        //新しいベクトルの絶対値
        double nz = sqrt(z_z);
       
        //元のベクトルを更新
        k = 0;
        for(int i=0; i<N; i++)
        {
            k += y[i]*z[i];    
            y[i] = z[i]/nz;    
        } 
    }
    
    //結果を出力
    printf("最大固有値は%lf\n", k);
    printf("固有ベクトルは(%lf, %lf, %lf)", y[0], y[1], y[2]);
}