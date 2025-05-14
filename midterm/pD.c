#include <stdio.h>
int main(){
    int n;
    long long int max=-10000000;
    scanf("%d",&n);
    int ans[n];
    long long int map[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=-10000000;
        }
    }
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&map[i][j]);
        }
    }
    if(n==1){
        for(int i=0;i<1;i++){
            if(max>map[0][i]){
                max=map[0][i];
                ans[0]==i;
            }
        }
        printf("%d",ans[0]+1);
    }
    if(n==2){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(i!=j){
                    long long int temp=0;
                    temp+=map[0][i];
                    temp+=map[1][j];
                    if(temp>max){
                        max=temp;
                        ans[0]=i;
                        ans[1]=j;
                    }
                }
            }
        }
        printf("%d %d",ans[0]+1,ans[1]+1);
    }
    if(n==3){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(i!=j && i!=k && j!=k ){
                    long long int temp=0;
                    temp+=map[0][i];
                    temp+=map[1][j];
                    temp+=map[2][k];
                    if(temp>max){
                        max=temp;
                        ans[0]=i;
                        ans[1]=j;
                        ans[2]=k;
                    }
                }
            }
        }
    }
    for(int j=0;j<3;j++){
        printf("%d ",ans[j]+1);
        }
    }

}