#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

int main(void)
{
    //手を出した回数の初期値0
    double g = 0;
    double c = 0;
    double p = 0;

    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        //最初の手をグーとする
        int a = 1;

        //一様乱数の値によって手を変えていく
        for(int j=0; j<100; j++)
        {
            double u = (double)rand()/RAND_MAX;

            //グーのとき
            if(a==1) 
            {
                if((0<=u) && (u<0.1))
                {
                    a = 1; 
                }
                if((0.1<=u) && (u<0.4))
                {
                    a = 2;
                }
                if((0.4<=u) && (u<1))
                {
                    a = 3;
                }
            }

            //チョキのとき
            else if(a==2) 
            {
                if((0<=u) && (u<0.3))
                {
                    a = 1; 
                }
                if((0.3<=u) && (u<0.5))
                {
                    a = 2;
                }
                if((0.5<=u) && (u<1))
                {
                    a = 3;
                }
            }

            //パーのとき
            else if(a==3) 
            {
                if((0<=u) && (u<0.5))
                {
                    a = 1; 
                }
                if((0.5<=u) && (u<0.6))
                {
                    a = 2;
                }
                if((0.6<=u) && (u<1))
                {
                    a = 3;
                }
            }
        } 
        
        //最後の手の回数を数える
        if(a==1)
        {
            g += 1;
        }
        if(a==2)
        {
            c += 1;
        }
        if(a==3)
        {
            p += 1;
        }   
    }

    //結果を出力
    printf("グーを出す確率 %lf\nチョキを出す確率 %lf\nパーを出す確率 %lf", g/N, c/N, p/N);
}