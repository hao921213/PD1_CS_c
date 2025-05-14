#include <stdio.h>
#include <math.h>
int n=0;
int A[100];
int B[100];
long long int multiply(int A[100],int B[100],int n){
    long long int result=0;
    for(int i=0;i<n;i++){
        result+=(A[i]*B[i]);
    }
    return result;
}
long long int power(int A[100],int n){
    long long int result=0;
    for(int i=0;i<n;i++){
        result+=pow(A[i],2);
    }
    return result;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&B[i]);
    }
    double a=(double)multiply(A,B,n);
    double b=(double)power(A,n);
    double c=(double)power(B,n);
    double ans=a/(pow(b*c,0.5));
    int ans1=ans*100;//無條件捨去 單純用.2f是四捨五入
    printf("%.2f\n",(double)ans1/100);
}