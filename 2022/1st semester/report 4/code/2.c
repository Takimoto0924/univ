#include <stdio.h>
#define N 2

int main (void)
{
    //二次元配列を定義
    int a[N][N] = {{1,2},{3,4}};
    int b[N][N] = {{5,6},{7,8}};
    int c[N][N];
    
    //ポインタを定義
    int *x, *y, *z;
    x = &a[0][0];
    y = &b[0][0];
    z = &c[0][0];

    //行列の積
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            *(z+N*i+j) = 0;
            for(int k=0; k<N; k++){
                *(z+N*i+j) += *(x+N*i+k) * *(y+N*k+j);
            }
        }
    }

    //結果を出力
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", *(z+N*i+j));
        }
        printf("\n");
    }
}