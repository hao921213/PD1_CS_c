#include <stdio.h>
long long int nums[200005]={};
long long int ans[200005]={};
int main(){
    int N=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lld",&nums[i]);
    }
    ans[0]=0;
    for(int i=1;i<N+1;i++){
        ans[i]=ans[i-1]+nums[i-1];
    }
    int t=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long int num1=0;
        long long int num2=0;
        scanf("%lld %lld",&num1,&num2);
        printf("%lld\n",(long long int)ans[num2]-ans[num1-1]);
    }
}