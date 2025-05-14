#include <stdio.h>

int main(){
    long long int a,b;
    long long int temp=0;
    int a_sign=1,b_sign=1;
    long long int ans;
    scanf("%lld %lld",&a,&b);
    if(b>a){
        temp=a;
        a=b;
        b=temp;
    }

    ans=a+b;

    if(a<0){
        if(ans>a){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    if(a>=0 && b<0){
        printf("NO\n");
    }
    if(b>0){
        if(ans<a){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }    

}