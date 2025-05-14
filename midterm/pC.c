#include <stdio.h>
int is_prim(int num){
    int ans=0;
    int count=2;
    while(1){
        if(num==count){
            break;
        }
        else{
            if(num%count==0){
                return 1;
            }
        }
        count++;
    }
    return 0;
}
int main(){
    int n=0;
    int num2=2;
    scanf("%d",&n);
    for(int i=0;i<n/2-1;i++){
        if(is_prim(n-num2)==0 && is_prim(num2)==0){
            break;
        }
        num2++;
    }
    if(num2<n-num2){
        printf("%d %d",num2,n-num2);        
    }
    else{
        printf("%d %d",n-num2,num2); 
    }

}