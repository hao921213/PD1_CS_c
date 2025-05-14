#include <stdio.h>
int p[1000000]={};
int ans[1000000]={};
int main(){
    int n=0;
    int q=0;
    long long int k=0;
    scanf("%d %d %lld",&n,&q,&k);
    long long int num1=0;
    long long int num2=0;
    int count=0;
    for(int i=0;i<n;i++){
        long long int temp=0;
        scanf("%lld",&temp);
        if(temp<k){
            p[i]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        count+=p[i-1];
        ans[i]=count;
    }
    for(int i=0;i<q;i++){
        scanf("%lld %lld",&num1,&num2);
        printf("%lld\n",ans[num2]-ans[num1-1]);
    }
    
}