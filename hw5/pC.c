#include <stdio.h>
int t[1000000]={0};

int main(){
    int input=0;
    int max=0;
    int num1=0;
    int num2=0;
    int count=0;
    scanf("%d",&input);
    for(int i=0;i<input;i++){
        scanf("%d %d",&num1,&num2);
        t[num1-1]++;
        t[num2-1]--;
    }
    for(int i=0;i<1000000;i++){
        count+=t[i];
        if(count>max){
            max=count;
        }
    }
    printf("%d",max);
}