#include <stdio.h>
#include <math.h>
int f(int a,int b,int c){
    return ((a+c)^(b-c))-(a&c&(b&2024)|(abs(c-b)));
}
int main(){
    int num[3]={};
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    int max=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(i!=j && j!=k && i!=k){
                    max=max>f(num[i],num[j],num[k])?max:f(num[i],num[j],num[k]);
                }
            }
        }
    }
    printf("%d",max);

}