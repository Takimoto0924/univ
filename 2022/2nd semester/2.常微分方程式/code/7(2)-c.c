#include <stdio.h>
#include <math.h>
#include <complex.h>

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

double norm(double x, double y, double z, double x0, double y0, double z0){
    double u = (x-x0)*(x-x0) + (y-y0)*(y-y0) + (z-z0)*(z-z0);
    
    return sqrt(u); 
}

int main(void){
    double dt = 0.01;
    double x0 = 1.0;
    double y0 = 0;       
    double z0 = 0;

    double n = 6;
    double x = 1 + pow(10,-n);
    double y = 0;
    double z = 0;

    FILE *fp;
    fp = fopen("7-2-6","w");

    for(double t=0; t<100; t+=dt){
        x0 = RKx(x0,y0,z0);
        y0 = RKy(x0,y0,z0);
        z0 = RKz(x0,y0,z0);

        x = RKx(x,y,z);
        y = RKy(x,y,z);
        z = RKz(x,y,z);

        double u = norm(x,y,z,x0,y0,z0);

        printf("%.16f %.16f\n",t,u);
        fprintf(fp, "%.16f %.16f\n",t,u);
    }

    fclose(fp);
}