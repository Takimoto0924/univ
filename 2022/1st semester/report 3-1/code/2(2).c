#include <stdio.h>
#define N 4
#define M 2

int main(void)
{
    //行列の定義
    double x[N][M] = {{1,1},{1,2},{1,3},{1,4}};
    double y[4] = {1.5, 3.2, 4.1, 5.2};

    //転置行列
    double tx[N][N];
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            tx[i][j] = x[j][i];
        }
    }

    //転置行列と元の行列の積
    double txx[M][M];
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            txx[i][j] = 0;

            for(int k=0; k<N; k++)
            {
                txx[i][j] = txx[i][j] + tx[i][k]*x[k][j];
            }
        }
    }

    //掃出し法に用いる行列
    double sweep[M][M*2];
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            sweep[i][j] = txx[i][j];
            sweep[i][M+j] = (i==j) ? 1 :0;
        }
    }

    //掃出し法
    for(int k=0; k<M; k++)
    {
        double a = 1/sweep[k][k];

        for(int j=0; j<M*2; j++)
        {
            sweep[k][j] *= a;
        }

        for(int i=0; i<M; i++)
        {
            if(i == k)
            {
                continue;
            }

            a = -sweep[i][k];

            for(int j=0; j<M*2; j++)
            {
                sweep[i][j] += sweep[k][j]*a;
            }
        }
    }

    //逆行列
    double inv[M][M];
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            inv[i][j] = sweep[i][M+j];
        }
    }

    //転置と元の行列の積の逆行列と転置行列の積
    double xxx[M][N];
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            xxx[i][j] = 0;

            for(int k=0; k<M; k++)
            {
                xxx[i][j] = xxx[i][j] + inv[i][k]*tx[k][j];
            }
        }
    }

    //ベータ
    double b[N];
    for(int i=0; i<M; i++)
    {
        b[i] = 0;

        for(int k=0; k<N; k++)
        {
            b[i] = b[i] + xxx[i][k]*y[k];
        }
    }

    //結果を出力
    for(int i=0; i<M; i++)
    {
        printf("%.1f \n", b[i]);
    }
}