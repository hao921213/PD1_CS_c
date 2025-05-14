#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    if(N==1){
        int X;
        scanf("%d",&X);
        for(int i=31;i>=0;i--){
            printf("%d",(X>>i)&1);
        }
    }
    else{
        float X;
        scanf("%f",&X);
        int *p=(int*)&X;
        for(int i=31;i>=0;i--){
            printf("%d",(*p>>i)&1);
        }        
    }
}