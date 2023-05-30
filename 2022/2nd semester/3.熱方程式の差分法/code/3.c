#include <stdio.h>
#include <math.h>
#define N 400
#define M 8000
#define L 1000

double u0(double x){
    return sqrt(2)*exp(-2*(x-5)*(x-5))/pow(M_PI,0.25);
}

double FE(double dx, double dt){

    double R[N+2];
    double I[N+2];
    double Ix[N+2];

    for(int j=1; j<=N; j++){
        R[j]=(u0((j-1)*dx-10)+u0(j*dx-10))/2;
    }

    R[0]=R[N];
    R[N+1]=R[1];

    for(int j=1; j<=N; j++){
        Ix[j]=-dt*(-(R[j-1]-2*R[j]+R[j+1])/(2*dx*dx)+((j-1/2)*dx-10)*((j-1/2)*dx-10)*R[j]/2);
    }

    Ix[0]=Ix[N];
    Ix[N+1]=Ix[1];

    double u[8][N];

    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
           R[j] = R[j]+dt*(-(Ix[j-1]-2*Ix[j]+Ix[j+1])/(2*dx*dx)+((j-1/2)*dx-10)*((j-1/2)*dx-10)*Ix[j]/2);
        }

        R[0]=R[N];
        R[N+1]=R[1];

        for(int j=1; j<=N; j++){
            I[j]=Ix[j]-dt*(-(R[j-1]-2*R[j]+R[j+1])/(2*dx*dx)+((j-1/2)*dx-10)*((j-1/2)*dx-10)*R[j]/2);
        }

        for(int k=1; k<=8; k++){
            if(i==k*L){
                for(int j=1; j<=N; j++){
                    u[k-1][j-1]=R[j]*R[j]+I[j]*Ix[j];
                }
            }
        }       

        for(int j=1; j<=N; j++){
            Ix[j]=I[j]; 
        }

        Ix[0]=Ix[N];
        Ix[N+1]=Ix[1];
    }

    FILE *fp;
    fp = fopen("3-1","w");

    for(int j=1; j<=N; j++){
        printf("%.3f", j*dx-10-0.025);
        fprintf(fp, "%.3f", j*dx-10-0.025);

        for(int k=1; k<=8; k++){
            printf("&%.8f", u[k-1][j-1]);
            fprintf(fp, " %.8f", u[k-1][j-1]);
        }

        printf("\\\\\n");
        fprintf(fp,"\n");
    }
}

int main(void){
    double dt = 0.001;
    double dx = 0.05;

    FE(dx, dt);
}