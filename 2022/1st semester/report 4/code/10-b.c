#include<stdio.h>

int main(void)
{
    //配列を定義
    double b[5]={0.1,0.2,0.3,0.4,0.5};
    double c[5];

    FILE *fp;

    //ファイルを書き込みモードで開く
    fp=fopen("10-b.txt","w");

    //文字列をファイルに書き込み
    fwrite(b,sizeof(double),5,fp);

    //ファイルを閉じる
    fclose(fp);

    //ファイルを書き込みモードで開く
    fp=fopen("10-b.txt","r");

    //文字列をファイルから読み取り
    fread(c,sizeof(double),5,fp);
    c[5]='\0';

    //読み取った文字列を出力
    printf("読み込んだ文字は\n");
    for(int i=0;i<5;i++){
        printf("%f",c[i]);
    }

    //ファイルを閉じる
    fclose(fp);
    
    return 0;
}