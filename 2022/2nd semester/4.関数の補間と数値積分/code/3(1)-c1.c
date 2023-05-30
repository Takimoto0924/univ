#include<stdio.h>
#include<math.h>
#define a 0.0
#define b M_PI
#define M 2

double f(double x){
    return 1+sin(x);
}

double x(double i, double n){
    double h=(b-a)/n;
    return a+i*h;
}

double I(double n){
    double I;
    double u;

    double y[2]={-1/sqrt(3),1/sqrt(3)};
    double w[2]={1,1};

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
    fp = fopen("c-2","w");

    double c=2+M_PI;

    for(int k=0; k<=10; k++){
        double n=pow(2,k);
        fprintf(fp,"%.16f %.16f\n", n, fabs(I(n)-c));
    }
}