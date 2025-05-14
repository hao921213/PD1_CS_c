#include<stdio.h>
int n=0;
int nums[100]={0};
void print(int num){
    if(num==n){
        for(int i=0;i<n;i++){
            printf("%d",nums[i]);
        }
        printf("\n");
        return; //終止，如果沒加會變成無限迴圈
    }
    for(int i=0;i<=2;i++){
        nums[num]=i;
        print(num+1);
    }
}
int main(){
    scanf("%d",&n);
    print(0);
}