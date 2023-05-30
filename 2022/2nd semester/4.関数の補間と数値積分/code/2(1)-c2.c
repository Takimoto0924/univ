#include<stdio.h>
#include<math.h>
#define a -1.0
#define b 1.0
#define n 4.0

double f(double x){
    return 1/(1+25*pow(x,2));
}

double x(double i){
    return a+(b-a)/n*i;
}

double l(double X, double i){
    double l=1;

    for(int j=0; j<=n; j++){
        if(j!=i){
            l=l*(X-x(j))/(x(i)-x(j));
        }
    }

    return l;
}

double P(double X){
    double p=0;

    for(int i=0; i<=n; i++){
        p+=f(x(i))*l(X,i);
    }

    return p;
}

int main(void){
    for(int i=0; i<=n; i++){
        printf("%.16f\n", f(x(i)));
    }

    FILE *fp;
    fp = fopen("c4","w");

    for(double k=a; k<b; k+=(b-a)/100){
        fprintf(fp, "%.2f %.16f\n", k, P(k));
    }
    fprintf(fp, "%.2f %.16f\n", b, P(b));

    fclose(fp);
}