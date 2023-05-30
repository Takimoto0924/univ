#include <stdio.h>
#include <math.h>

double RK2(double dt){
    FILE *fp;
    fp = fopen("4-2-0205","w");

    double u = 1.0;
    double u0;

    for(double t=0; t<10; t+=dt){
        u0 = u + (-10*u+1)*dt;
        u = u + (-10*u+1-10*u0+1)*dt/2;

        printf("%.16f %.16f\n",t,u);
        fprintf(fp,"%.16f %.16f\n",t,u);
    }

    fclose(fp);
}

int main(void){
    double dt[] = {0.01, 0.19, 0.205};
    RK2(dt[2]);
}