#include<stdio.h>

int main(void)
{
    //配列を定義
    int a[5]={1,2,3,4,5};
    int c[5];

    FILE *fp;

    //ファイルを書き込みモードで開く
    fp=fopen("10-a.txt","w");

    //ファイルに文字列を書き込み
    fwrite(a,sizeof(int),5,fp);

    //ファイルを閉じる
    fclose(fp);

    //ファイルを書き込みモードで開く
    fp=fopen("10-a.txt","r");

    //文字列をファイルから読み取り
    fread(c,sizeof(int),5,fp);
    c[5]='\0';

    //読み取った文字列を出力
    printf("読み込んだ文字は\n");
    for(int i=0;i<5;i++){
        printf("%d",c[i]);
    }

    //ファイルを閉じる
    fclose(fp);

    return 0;
}