#include <stdio.h>
#include <math.h>

double AB2(double dt){
    double u = 1.0;
    double u1 = u;
    double u2 = exp(-dt);

    for(double t=0; t<1; t+=dt){
        u = u1 + (3*u1-u2)*dt/2;
        u2 = u1;
        u1 = u;
    }

    return fabs(u-exp(1));
}

int main(void){
    FILE *fp;
    fp = fopen("3-2","w");

    for(double dt=1; dt>=pow(2,-11); dt/=2){ 
        printf("%.16f %.16f\n", dt, AB2(dt));
        fprintf(fp,"%.16f %.16f\n", dt, AB2(dt));
    }

    fclose(fp);
}