#include <stdio.h>
int main(){
    int n=0;
    int q=0;
    int k=0;
    scanf("%d %d %d",&n,&q,&k);
    int num1=0;
    int num2=0;
    int p[n]={};
    int ans[n+1]={};
    int count=0;
    for(int i=0;i<n;i++){
        int temp=0;
        scanf("%d",&temp);
        if(temp<k){
            p[i]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        count+=p[i-1];
        ans[i]=count;
    }
    for(int i=0;i<q;i++){
        scanf("%d %d",&num1,&num2);
        printf("%d\n",ans[num2]-ans[num1-1]);
    }
    
}