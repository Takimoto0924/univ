#include <stdio.h>
#include <stdlib.h>
#define N 1000000

//配列の順序をランダムに並び替える関数を定義
void shuffle(int array[], int size)
{
    for(int i=0; i<size; i++){
        int j = rand()%size;

        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

int main(void)
{
    //百万個のメモリを確保
    int *x;
    x=(int*)malloc(N*sizeof(int));

    //メモリに値を代入
    for(int i=0; i<N; i++){
        x[i] = i+1;
    }

    //メモリの値をランダムに並び替え
    shuffle(x, N);

    //結果を出力
    for(int i=0; i<N; i++){
        printf("%d ", x[i]);
    }

    //メモリの解放
    free(x);
}