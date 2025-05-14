#include <stdio.h>
#include <math.h>
char num1[101]={};
char num2[101]={};
char ans[201]={};
int main(){
    int odd=0;
    int even=0;
    int index=0;
    scanf("%s %s",num1,num2);
    for(int i=0;num1[i]!='\0';i++){
        ans[index++]=num1[i];
    }
    for(int i=0;num2[i]!='\0';i++){
        ans[index++]=num2[i];
    }
    ans[index]='\0';
    for(int i=0;ans[i]!='\0';i++){
        if((i+1)%2==1){
            odd+=ans[i]-'0';
        }
        else{
            even+=ans[i]-'0';
        }
        printf("%c",ans[i]);
    }
    printf("\n");
    if(abs(odd-even)%11==0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
