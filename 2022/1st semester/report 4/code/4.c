#include <stdio.h>
#include <stdlib.h>
#define N 128

//配列の順序をランダムに並び替える関数
void shuffle(int array[], int size)
{
    for(int i=0; i<size; i++){
        int j = rand()%size;

        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

//マージソートを実行する関数
void merge_sort(int array[], int left, int right)
{
    int i,j,k,mid;
    int array2[N];
    int *x,*y;

    x = &array[0];
    y = &array2[0];

    if(left<right){

        //前半と後半にデータを分け小さい順にソート
        mid = (left+right)/2;
        merge_sort(array, left, mid);
        merge_sort(array, mid+1, right);

        //ソートされた前半の配列をメモリに代入
        for(i=mid; i>=left; i--){
            *(y+i) = *(x+i);
        }

        //ソートされた後半の配列をメモリに代入
        for(j=mid+1; j<=right; j++){
            *(y+right-(j-(mid+1))) = *(x+j);
        }

        i = left;
        j = right;

        //前半の先頭の値と後半の先頭の値のうち、小さい方を順に取得
        for(k=left; k<=right; k++){
            if(*(y+i)<*(y+j)){
                *(x+k) = *(y+i++);
            }
            else{
                *(x+k) = *(y+j--);
            }
        }
    }
}

int main(void)
{
    //配列を定義
    int a[N];

    for(int i=0; i<N; i++){
        a[i] = i+1;
    }

    //ランダムに並び替え
    shuffle(a, N);

    //並び替えた後の配列を出力
    for(int i=0; i<N; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    //マージソートを実行
    merge_sort(a, 0, N-1);

    //結果を出力
    for(int i=0; i<N; i++){
        printf("%d ", a[i]);
    }
}