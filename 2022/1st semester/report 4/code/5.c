#include <stdio.h>
#include<string.h>

#define N 16
#define C 1800


//構造体を宣言
typedef struct
{
int number;
int price;
int value;
} knap;

//構造体変数を宣言
knap knaps[N] = {
    {1,178,20},
    {2,255,24},
    {3,164,10},
    {4,334,35},
    {5,1000,100},
    {6,108,13},
    {7,789,70},
    {8,435,35},
    {9,95,22},
    {10,324,21},
    {11,52,6},
    {12,248,27},
    {13,512,60},
    {14,400,43},
    {15,122,10},
    {16,870,87}
};

//ナップザック問題を解く関数
int knapsack(int i, int c)
{
    int put_value;
    int no_put_value;
    int max_value;
    int a[N];

    //入れる商品がない場合
    if (i > N - 1){
        return 0;
    }

    //対象の商品を入れない場合の最大価値
    no_put_value = knapsack(i+1, c);
    
    //対象の商品が入る場合/
    if (knaps[i].price <= c) {
        //対象の商品を入れた場合の価値
        put_value = knapsack(i+1, c - knaps[i].price) + knaps[i].value;
    }

    //対象の商品が入らない場合
    else {
        //対象の商品を入れない場合の最大価値より小さいため負の値を置く        
        put_value = -1;
    }
    
    //t対象の商品を入れた場合と入れなかった場合の大きい方の価値を取得
    if (no_put_value > put_value) {
        max_value = no_put_value;
        a[i]=0;
    }
    
    else {
        max_value = put_value;
        a[i]=1;
    }

    return max_value;
}

int main(void)
{
    int i;
    int ret;

    //ナップザック問題の解を取得
    ret = knapsack(0, C);

    int price = 0;

    //商品の内訳を出力
    printf("商品の内訳は\n");
    for(i=0;i<N;i++)
    {
        if (knapsack(0,C)<=knapsack(0,C-knaps[i].price)+knaps[i].value){

            price += knaps[i].price;
            printf("%d,%d,%d\n", knaps[i].number, knaps[i].price, knaps[i].value);
        }
    }

    //結果を出力
    printf("価値の合計は%d\n支払額は%d円", ret, price);

    return 0;
}