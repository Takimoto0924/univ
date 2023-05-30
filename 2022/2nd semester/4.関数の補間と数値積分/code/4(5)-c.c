#include<stdio.h>
#include<math.h>
#define a 0.0
#define b 1.0
#define M 3
#define N 3

double X(double i, int n){
    double h=(b-a)/n;
    return a+i*h;
}

double t(double x, int i, int n){
    if(x>=X(i-1,n) && x<X(i,n)){
        return (x-X(i-1,n))/(X(i,n)-X(i-1,n));
    }

    else if(x>=X(i,n) && x<X(i+1,n)){
        return (X(i+1,n)-x)/(X(i+1,n)-X(i,n));
    }

    else{
        return 0;
    }
}

double dt(double x,int i, int n){
    if(x>=X(i-1,n) && x<X(i,n)){
        return 1/(X(i,n)-X(i-1,n));
    }

    else if(x>=X(i,n) && x<X(i+1,n)){
        return -1/(X(i+1,n)-X(i,n));
    }

    else{
        return 0;
    }
}

double dA(double x, int i, int j, int n){
    return exp(-x*x)*dt(x,i,n)*dt(x,j,n)-6*exp(-x*x)*t(x,i,n)*t(x,j,n);
}

double dB(double x, int i, int n){
    return -16*x*exp(-x*x)*t(x,i,n);
}

int main(void){
    double y[3]={-sqrt(3.0/5.0),0,sqrt(3.0/5.0)};
    double w[3]={5.0/9.0,8.0/9.0,5.0/9.0};
    double u;
    int n=pow(2,N);

    double A[n-1][n-1];

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            A[i-1][j-1]=0;
            for(int k=0; k<n; k++){
                for(int m=0; m<M; m++){
                    u=(y[m]+1)*(X(k+1,n)-X(k,n))/2+X(k,n);
                    A[i-1][j-1]+=w[m]*dA(u,i,j,n)*(X(k+1,n)-X(k,n))/2;
                }    
            }
        }
    }

    double B[n-1];

     for(int i=1; i<n; i++){
        B[i-1]=0;
        for(int k=0; k<n; k++){
            for(int m=0; m<M; m++){
                u=(y[m]+1)*(X(k+1,n)-X(k,n))/2+X(k,n);
                B[i-1]+=w[m]*dB(u,i,n)*(X(k+1,n)-X(k,n))/2;
            }    
        }
    }
    
    double B0[n-2];

    B0[0]=A[0][1]/A[0][0];
    for(int i=1; i<=n-3; i++){
        B0[i]=A[i][i+1]/(A[i][i]-A[i-1][i]*B0[i-1]);
    }

    double D0[n-1];

    D0[0]=B[0]/A[0][0];
    for(int i=1; i<=n-2; i++){
        D0[i]=(B[i]-A[i-1][i]*D0[i-1])/(A[i][i]-A[i-1][i]*B0[i-1]);
    }

    double C[n+1];

    C[n]=0;
    for(int i=n-1; i>=0; i--){
        C[i]=D0[i-1]-B0[i-1]*C[i+1];
    }

    FILE *fp;
    fp = fopen("3","w");

    for(int i=0; i<=n; i++)
    {
        fprintf(fp,"%.16f %.16f\n", X(i,n), C[i]);
    }

    fclose(fp);
}