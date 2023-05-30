#include <stdio.h>
#include <math.h>

double CN(double dt){
    FILE *fp;
    fp = fopen("4-1-0205","w");

    double u = 1.0;

    for(double t=0; t<10; t+=dt){
        u = (1-5*dt)/(1+5*dt)*u + dt/(1+5*dt);

        printf("%.16f %.16f\n",t,u);
        fprintf(fp,"%.16f %.16f\n",t,u);
    }
    
    fclose(fp);
}

int main(void){
    double dt[] = {0.01, 0.19, 0.205};
    CN(dt[2]);
}