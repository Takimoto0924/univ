#include <stdio.h>
#define N 10

int main(void)
{
    //データを配列として定義
    int a[N] = {95,90,75,85,60,100,80,70,75,65};

    //配列の右の数が左の数よりも小さければ二数を入れ替え
    for(int i=0; i<=N-2; i++)
    {
        for(int j=N-1; j>=i+1; j--)
        {
            if(a[j-1]>a[j])
            {
                int b = a[j];
                a[j] = a[j-1];
                a[j-1] = b;
            }
        }

        //小さい方から順に結果を出力
        printf("%d ", a[i]);
    }

    printf("%d", a[N-1]);
}