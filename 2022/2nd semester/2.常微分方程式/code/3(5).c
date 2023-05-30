#include <stdio.h>
#include <math.h>

double RK4(double dt){
    double u = 1.0;
    double f1;
    double f2;
    double f3;
    double f4;

    for(double t=0; t<1; t+=dt){
        f1 = u;
        f2 = u + f1*dt/2;
        f3 = u + f2*dt/2;
        f4 = u + f3*dt;
        u = u + (f1+2*f2+2*f3+f4)*dt/6;
    }

    return fabs(u-exp(1));
}

int main(void){
    FILE *fp;
    fp = fopen("3-5","w");

    for(double dt=1; dt>=pow(2,-11); dt/=2){ 
        printf("%.16f %.16f\n", dt, RK4(dt));
        fprintf(fp,"%.16f %.16f\n", dt, RK4(dt));
    }

    fclose(fp);
}