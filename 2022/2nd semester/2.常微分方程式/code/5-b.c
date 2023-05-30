#include <stdio.h>
#include <math.h>

double fu(double dt){
    FILE *fp;
    fp = fopen("5-019","w");

    double u = 1.0;
    double u1 = u;
    double u2 = exp(-dt)/2 + 0.5;

    for(double t=0; t<10; t+=dt){
        u = u2 + 2*(-2*u1+1)*dt;
        u2 = u1;
        u1 = u;

        printf("%.16f %.16f\n",t,u);
        fprintf(fp,"%.16f %.16f\n",t,u);
    }

    fclose(fp);
}

int main(void){
    double dt[] = {0.01, 0.19, 0.205};
    fu(dt[1]);
}