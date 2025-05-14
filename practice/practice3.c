#include <stdio.h>

int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    if(num1<num2){
        int temp=num1;
        num1=num2;
        num2=temp;
    }
    int ans=num2;
    while(1){
        if(num1%ans==0 && num2%ans==0){
            break;
        }
        else{
            ans--;
        }
    }
    printf("%d\n",ans);
}