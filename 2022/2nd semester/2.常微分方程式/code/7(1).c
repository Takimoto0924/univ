#include <stdio.h>
#include <math.h>

double dx(double x, double y, double z){
    return 10*(y-x);
}

double dy(double x, double y, double z){
    return 28*x-y-x*z;
}

double dz(double x, double y, double z){
    return x*y-z*8/3;
}

double RKx(double x, double y, double z){
    double dt = 0.01;
    double f1 = dx(x,y,z);
    double f2 = dx(x,y,z) + f1*dt/2;
    double f3 = dx(x,y,z) + f2*dt/2;
    double f4 = dx(x,y,z) + f3*dt;
    
    return x + (f1+2*f2+2*f3+f4)*dt/6;
}

double RKy(double x, double y, double z){
    double dt = 0.01;
    double f1 = dy(x,y,z);
    double f2 = dy(x,y,z) + f1*dt/2;
    double f3 = dy(x,y,z) + f2*dt/2;
    double f4 = dy(x,y,z) + f3*dt;
    
    return y + (f1+2*f2+2*f3+f4)*dt/6;
}

double RKz(double x, double y, double z){
    double dt = 0.01;
    double f1 = dz(x,y,z);
    double f2 = dz(x,y,z) + f1*dt/2;
    double f3 = dz(x,y,z) + f2*dt/2;
    double f4 = dz(x,y,z) + f3*dt;
    
    return z + (f1+2*f2+2*f3+f4)*dt/6;
}

int main(void){
    double x = 1.0;
    double y = 0;
    double z = 0;
    double dt = 0.01;

    FILE *fp;
    fp = fopen("7-1","w");

    for(double t=0; t<100; t+=dt){
        x = RKx(x,y,z);
        y = RKy(x,y,z);
        z = RKz(x,y,z);

        printf("%.16f %.16f %.16f %.16f\n",t,x,y,z);
        fprintf(fp,"%.16f %.16f %.16f %.16f\n",t,x,y,z);
    }

    fclose(fp);
}