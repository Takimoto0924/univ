#include<stdio.h>
#include<math.h>
#define a 1.0
#define b 2.0
#define M 3

double f(double x){
    return 1/x;
}

double x(double i, double n){
    double h=(b-a)/n;
    return a+i*h;
}

double I(double n){
    double I;
    double u;

    double y[3]={-sqrt(3.0/5.0),0,sqrt(3.0/5.0)};
    double w[3]={5.0/9.0,8.0/9.0,5.0/9.0};

    for(int i=0; i<n; i++){
        for(int m=0; m<M; m++){
            u=(y[m]+1)*(x(i+1,n)-x(i,n))/2+x(i,n);
            I+=w[m]*f(u)*(x(i+1,n)-x(i,n))/2;
        }
    }

    return I;
}

int main(void){
    FILE *fp;
    fp = fopen("a-3","w");

    double c=log(2);

    for(int k=0; k<=10; k++){
        double n=pow(2,k);
        fprintf(fp,"%.16f %.16f\n", n, fabs(I(n)-c));
    }
}