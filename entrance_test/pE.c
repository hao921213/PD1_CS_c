#include <stdio.h>
#include <string.h>
char input[10][100];
char ans[100];
char get_c(char *input1){
    for(int i=0;input1[i]!='\0';i++){
        if(input1[i]=='<'){
            return input1[i+1];
        }
    }
    return 0;
}
int main(){
    int n=0;
    int flag=0;
    scanf("%d",&n);
    getchar();
    int index=0;
    int count=0;
    for(int i=0;i<n;i++){
        fgets(input[i],sizeof(input[i]),stdin);
        input[i][strcspn(input[i],"\n")]='\0';
    }
    for(int i=0;i<n;i++){
        count=0;
        char c=get_c(input[i]);
        for(int j=0;input[i][j]!='\0';j++){
            if(input[i][j]==' '){
                count++;
            }
        }
        if(count/4>0){
            index--;
        }
        ans[index++]=c;
        ans[index++]='+';
    }
    if(ans[--index]=='+'){
        ans[index]='\0';
    }
    else{
        ans[index]='\0';
    }
    printf("%s",ans);
}