#include <stdio.h>

int main(){
    int num=0;
    int start=0;
    int count=0;
    scanf("%d",&num);
    int speeds[num];
    for(int i=0;i<num;i++){
        scanf("%d",&speeds[i]);
    }
    for(int i=0;i<num;i++){
        if(speeds[i]>=40 && speeds[i]<=60 && start==0){
            start=1;
            count++;
        }
        else{
            if(speeds[i]<40 || speeds[i]>60){
                start=0;
            }
        }
    }
    printf("%d",count);
}