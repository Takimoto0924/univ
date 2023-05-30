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
    double u=0;

    for(int i=0; i<n; i++){
        u+=f((x(i,n)+x(i+1,n))/2);
    }

    double h=(b-a)/n;
    double I=h*u;

    return I;
}

int main(void){
    FILE *fp;
    fp = fopen("b-1","w");

    for(int k=0; k<=10; k++){
        double n=pow(2,k);
        fprintf(fp,"%.16f %.16f\n", n, I(n));
    }
}