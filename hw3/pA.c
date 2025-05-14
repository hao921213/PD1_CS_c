#include <stdio.h>

int main(){
        int n,c,k;
        scanf("%d %d %d",&n,&c,&k);
        int ans[n];
        int i=0;
        while(c>0){

                ans[i]+=1;
                c--;
                if(i==n-1){
                        if(c==1){
                                ans[i]+=1;
                                break;
                        }
                        else{
                                ans[i]+=1;
                                c--;
                                i-=1;
                        }
                }
                else{
                        i+=1;
                }
        }
        printf("%d\n",ans[k-1]);
}