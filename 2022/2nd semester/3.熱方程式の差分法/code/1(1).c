#include <stdio.h>
#include <math.h>
#define N 20
#define M 500

double u0(double x){
    return exp(-0.5*(x-5)*(x-5))/sqrt(2*M_PI);
}

double FE(double dx, double dt){

    double c = dt/(dx*dx);
    double u[M+1][N+2];

    for(int j=1; j<=N; j++){
        u[0][j] = (u0((j-1)*dx)+u0(j*dx))/2;
    }

    u[0][0] = 0;
    u[0][N+1] = 0;
    
    for(int i=0; i<M; i++){

        for(int j=1; j<=N; j++){
            u[i+1][j] = u[i][j] + c*(u[i][j-1]-2*u[i][j]+u[i][j+1]);
        }

        u[i+1][0] = 0;
        u[i+1][N+1] = 0;
    }

    FILE *fp;
    fp = fopen("1-1","w");

    for(int j=1; j<=N; j++){
        printf("%.2f", j*dx-0.25);
        fprintf(fp, "%.2f", j*dx-0.25);

        for(int k=1; k<=5; k++){
            printf("&%.8f", u[100*k][j]);
            fprintf(fp, " %.8f", u[100*k][j]);
        }

        printf("\\\\\n");
        fprintf(fp,"\n");
    }

    fclose(fp);
}

int main(void){
    double dt = 0.01;
    double dx = 0.5;

    FE(dx, dt);
}