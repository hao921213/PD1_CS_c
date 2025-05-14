#include <stdio.h>
char map[10];
int main(){
    int n=0;
    int m=0;
    char temp;
    int pos=0;
    scanf("%d %d",&n,&m);
    scanf("%c",&temp);
    for(int i=0;i<n;i++){
        scanf("%c",&map[i]);
        if(map[i]=='V'){
            pos=i;
        }
    }
    scanf("%c",&temp);
    for(int i=0;i<m;i++){
        char a;
        int b=0;
        scanf("%c%d",&a,&b);
        scanf("%c",&temp);
        if(a=='L'){
            if(pos-b<0){
                printf("Out of range\n");
                continue;
            }
            else{
                char change=map[pos];
                if(map[pos-b]=='+'){
                    map[pos-b]='.';
                }
                map[pos]=map[pos-b];
                map[pos-b]=change;
                pos-=b;
            }
        }
        else{
            if(pos+b>=n){
                printf("Out of range\n");
                continue;
            }
            else{
                char change=map[pos];
                if(map[pos+b]=='+'){
                    map[pos+b]='.';
                }
                map[pos]=map[pos+b];
                map[pos+b]=change;
                pos+=b;
            }
        }
        for(int j=0;j<n;j++){
            printf("%c",map[j]);
        }
        printf("\n");
    }
}