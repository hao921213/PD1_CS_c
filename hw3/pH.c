#include <stdio.h>

int main(){
    long long num1;
    long long num2;
    int negative=0;

    scanf("%lld %lld",&num1,&num2);

    if(num1<num2){
        long long temp=num2;
        num2=num1;
        num1=temp;
    }

    if(num1>0 && num2<0){
        long long ans;
        ans=num1+num2;
        printf("%lld\n",ans);
    }
    else{
        if(num1<0){
            num1*=-1;
            num2*=-1;
            negative=1;
        }
        unsigned long long ans;
        if(negative==1){
            if(num1==-9223372036854775808 && num2==-9223372036854775808){
                printf("-18446744073709551616\n");
            }
            else{
                ans=(unsigned long long)(num1+num2);
                printf("-%llu\n",ans);
            }

        }
        else{
            ans=(unsigned long long)(num1+num2);
            printf("%llu\n",ans);
        }
    }
  

}