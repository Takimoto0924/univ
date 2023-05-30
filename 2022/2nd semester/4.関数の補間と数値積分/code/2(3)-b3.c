#include<stdio.h>
#include<math.h>
#define a -1.0
#define b 1.0

double f(double x){
    return exp(5*x);
}

double x(double i, double n){
    double h=(b-a)/n;
    return a+i*h;
}

double I(double n){
    double u1=0;
    double u2=0;

    for(int i=1; i<n; i++){
        u1+=f(x(i,n));
    }

    for(int i=0; i<n; i++){
        u2+=f((x(i,n)+x(i+1,n))/2);
    }


    double h=(b-a)/n;
    double I=h/6*(f(x(0,n))+2*u1+f(x(n,n))+4*u2);

    return I;
}

int main(void){
    FILE *fp;
    fp = fopen("b-3","w");

    double c=2*sinh(5)/5;

    for(int k=0; k<=10; k++){
        double n=pow(2,k);
        fprintf(fp,"%.16f %.16f\n", n, fabs(I(n)-c));
    }
}