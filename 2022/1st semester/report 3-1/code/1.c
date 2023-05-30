#include <stdio.h>
#define N 3

int main(void)
{
    //行列の定義    
    double a[N][N] = {{1,2,3},{4,5,6},{7,8,9}};

    //転置行列
    double a_t[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            a_t[i][j] = a[j][i];
        }
    }

    //結果をターミナルに出力
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%.lf ", a_t[i][j]);
        }
        printf("\n");
    }
}