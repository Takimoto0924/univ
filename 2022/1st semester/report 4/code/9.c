#include<stdio.h>

int main()
{
    FILE *fp;
    char x[64];

    //ファイルを書き込みモードで開く
    fp=fopen("9.txt","w");

    //文字列をファイルに書き込み
    fprintf(fp,"%s","HelloWorld!");

    //ファイルを閉じる
    fclose(fp);

    //ファイルを読み取りモードで開く
    fp=fopen("9.txt","r");

    //文字列をファイルから読み取る
    fscanf(fp,"%s",x);

    //読み取った文字列を出力
    printf("%s",x);

    //ファイルを閉じる
    fclose(fp);
    
    return 0;
}