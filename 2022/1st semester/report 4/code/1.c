#include <stdio.h>

//構造体を宣言
typedef struct
{
    int number;
    int japanese;
    int math;
} student;

int main (void)
{
    //構造体変数を宣言
    student std[] =
    {
        {1,95,78},
        {2,45,83},
        {3,100,90},
        {4,20,15},
        {5,43,70},
    };

    //入力した学籍番号に対応すして結果を出力
    int no;
    printf("学籍番号を入力してください:");
    scanf("%d", &no);
    printf("国語%d点、数学%d点", std[no-1].japanese, std[no-1].math);
}