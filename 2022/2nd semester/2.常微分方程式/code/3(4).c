#include <stdio.h>
#include <math.h>

double RK2(double dt){
    double u = 1.0;
    double u0;

    for(double t=0; t<1; t+=dt){
        u0 = u + u*dt;
        u = u + (u+u0)*dt/2;
    }

    return fabs(u-exp(1));
}

int main(void){
    FILE *fp;
    fp = fopen("3-4","w");

    for(double dt=1; dt>=pow(2,-11); dt/=2){ 
        printf("%.16f %.16f\n", dt, RK2(dt));
        fprintf(fp,"%.16f %.16f\n", dt, RK2(dt));
    }

    fclose(fp);
}