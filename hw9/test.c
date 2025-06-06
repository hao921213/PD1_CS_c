#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef double (*F)(double,int);
typedef double (*powerF)(F,double,int,int);
double power(double x,int n){
    return pow(x,n);
}
double multiply(double x,int n){
    return (double)x*n;
}
double divide(double x, int n){
    return (double)x/n;
}
double powerpower(double (*F)(double,int),double x,int n,int m){
    return pow(F(x,n),m);
}
double powermultiply(double (*F)(double,int),double x,int n,int m){
    return (double)F(x,n)*m;
}
double powerdivide(double (*F)(double,int),double x, int n,int m){
    return (double)F(x,n)/m;
}
int main(int argc,char *argv[]){
    double x=6.5;
    int n=8;
    int m=3;
    F f[3];
    powerF powerf[3];
    f[0]=power;
    f[1]=multiply;
    f[2]=divide;
    powerf[0]=powerpower;
    powerf[1]=powermultiply;
    powerf[2]=powerdivide;
    printf("%f\n",pow(6.5,24));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%f\n",powerf[i](f[j],x,n,m));
        }
    }
}