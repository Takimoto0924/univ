#include <stdio.h>
#include <math.h>

double FE(double dt){
    double u = 1.0;

    for(double t=0; t<1; t+=dt){
        u = u + u*dt;
    }

    return fabs(u-exp(1));
}

int main(void){
    FILE *fp;
    fp = fopen("3-1","w");

    for(double dt=1; dt>=pow(2,-11); dt/=2){
        printf("%.16f %.16f\n", dt, FE(dt));
        fprintf(fp,"%.16f %.16f\n", dt, FE(dt));
    }

    fclose(fp);
}