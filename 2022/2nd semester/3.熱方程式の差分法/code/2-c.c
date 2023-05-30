#include <stdio.h>
#include <math.h>
#define N 4000
#define M 40000
#define L 10000

double u0(double x){
    return 1/((1+exp(1.0*x-5))*(1+exp(1.0*x-5)));
}

double fu(double u){
    return u*(1-u);
}

double FE(double dx, double dt){

    double c = dt/(dx*dx);
    
    double u[N+2];    

    for(int j=1; j<=N; j++){
        u[j] = (u0((j-1)*dx)+u0(j*dx))/2;
    }

    u[0]=1;
    u[N+1]=0;

    double x[N+2];
    double ux[4][N];

    for(int i=1; i<=M; i++){

        for(int j=1; j<=N; j++){
            x[j] = u[j] + c*(u[j-1]-2*u[j]+u[j+1]) + fu(u[j])*dt;
        }

        for(int j=1; j<=N; j++){
            u[j] = x[j];
        }

        for(int k=1; k<=4; k++){

            if(i==k*L){

                for(int j=1; j<=N; j++){
                    ux[k-1][j-1]=u[j];
                }
            }
        }
    }

    FILE *fp;
    fp = fopen("2-1-1","w");

    for(int j=1; j<=N; j++){
        printf("%.3f", j*dx-0.025);
        fprintf(fp, "%.3f", j*dx-0.025);

        for(int k=1; k<=4; k++){
            printf("&%.8f", ux[k-1][j-1]);
            fprintf(fp, " %.8f", ux[k-1][j-1]);
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