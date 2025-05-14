#include <stdio.h>
void f(int x,int y);
int check();
int arr[4][4]={0};//多開一個位子就不用管index跟現實的差別
int count=0;
void f(int x,int y){
    if(x==4){
        if(check()==1)count++;
        return;
    }
    if(x==1 && y==1){
        f(x,y+1);
        return;
    }
    if(x==2 && y==3){
        f(x+1,1);
        return;
    }
    if(x==3 && y==1){
        f(x,y+1);
        return;
    }
    for(int i=-5;i<5;i++){
        arr[x][y]=i;
        if(y==3)f(x+1,1);
        else f(x,y+1);
    }

}
int check(){
    int ans[8]={0};
    for(int i=1;i<=3;i++){
        ans[0]+=arr[1][i];
        ans[1]+=arr[2][i];
        ans[2]+=arr[3][i];
        ans[3]+=arr[i][1];
        ans[4]+=arr[i][2];
        ans[5]+=arr[i][3];
        ans[6]+=arr[i][i];
        ans[7]+=arr[i][4-i]; 
    }
    int temp=ans[0];
    for(int i=0;i<8;i++){
        if(temp!=ans[i])return -1;
    }
    return 1;
}
int main(){
    scanf("%d %d %d",&arr[1][1],&arr[2][3],&arr[3][1]);
    f(1,1);
    printf("%d",count);
}