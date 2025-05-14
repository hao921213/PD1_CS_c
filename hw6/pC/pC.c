#include <stdio.h>
#include "pC.h"
void f(int n,int *ans){
    int num=0;
    int a=1;
    int b=1;
    for(int i=3;i<=n;i++){
        num=a+b;
        int temp=a;
        a=num;
        b=temp;
    }
    if(n==1 || n==2){
        num=1;
    }
    *ans=num;
}