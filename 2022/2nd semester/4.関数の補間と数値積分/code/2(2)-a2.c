#include<stdio.h>
#include<math.h>
#define a 1.0
#define b 2.0

double f(double x){
    return 1/x;
}

double x(double i, double n){
    double h=(b-a)/n;
    return a+i*h;
}

double I(double n){
    double u=0;

    for(int i=1; i<n; i++){
        u+=f(x(i,n));
    }

    double h=(b-a)/n;
    double I=h/2*(f(x(0,n))+2*u+f(x(n,n)));

    return I;
}

int main(void){
    FILE *fp;
    fp = fopen("a-2","w");

    for(int k=0; k<=10; k++){
        double n=pow(2,k);
        fprintf(fp,"%.16f %.16f\n", n, I(n));
    }
}