#include <stdio.h>
#include <math.h>

double AB3(double dt){
    double u = 1.0;
    double u1 = u;
    double u2 = exp(-dt);
    double u3 = exp(-2*dt);

    for(double t=0; t<1; t+=dt){
        u = u1 + (23*u1-16*u2+5*u3)*dt/12;
        u3 = u2;
        u2 = u1;
        u1 = u;
    }

    return fabs(u-exp(1));
}

int main(void){
    FILE *fp;
    fp = fopen("3-3","w");

    for(double dt=1; dt>=pow(2,-11); dt/=2){ 
        printf("%.16f %.16f\n", dt, AB3(dt));
        fprintf(fp,"%.16f %.16f\n", dt, AB3(dt));
    }

    fclose(fp);
}