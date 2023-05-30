#include<stdio.h>
#include<math.h>
#define N 200
#define M 500

double u0(double x){
    return exp(-0.5*(x-5)*(x-5))/sqrt(2*M_PI);
}

double CK(double dx, double dt){

    double c = dt/(dx*dx);
    double u[M+1][N+2];

    for(int j=1; j<=N; j++){
        u[0][j] = (u0((j-1)*dx)+u0(j*dx))/2;
    }

    u[0][0] = u[0][1];
    u[0][N+1] = u[0][N];

    double a_n[N];
    double b_n[N-1];
    double c_n[N-1];

    for(int j=0; j<N-1; j++){
        a_n[j]=1+c;
        b_n[j]=-c/2;
        c_n[j]=-c/2;
    }
    a_n[0]=1+c/2;
    a_n[N-1]=1+c/2;

    double a[N];
    double b[N-1];

    a[0]=a_n[0];
    for(int j=1; j<N; j++){
        b[j-1]=b_n[j-1]/a[j-1];
        a[j]=a_n[j]-c_n[j-1]*b[j-1];
    }

    for(int i=0; i<M; i++){

        double z[N];

        z[0]=(1-c/2)*u[i][1]+(c/2)*u[i][2];
        for(int j=1; j<N-1; j++){
            z[j]=(1-c)*u[i][j+1]+(c/2)*u[i][j]+(c/2)*u[i][j+2];
        }
        z[N-1]=(1-c/2)*u[i][N]+(c/2)*u[i][N-1];

        double y[N];

        y[0]=z[0]/a[0];
        for(int j=1; j<N; j++){
            y[j]=(z[j]-c_n[j-1]*y[j-1])/a[j];
        }

        u[i+1][N]=y[N-1];
        for(int j=N-1; j>0; j--){
            u[i+1][j]=y[j-1]-b[j-1]*u[i+1][j+1];
        }
        u[i+1][0] = 0;
        u[i+1][N+1] = 0;

    }

    FILE *fp;
    fp = fopen("1-4","w");

    for(int j=1; j<=N; j++){
        printf("%.3f", j*dx-0.025);
        fprintf(fp, "%.3f", j*dx-0.025);

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
    double dx = 0.05;

    CK(dx, dt);
}