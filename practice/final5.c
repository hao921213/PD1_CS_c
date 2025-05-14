#include <stdio.h>
int plus(int a,int b){
    return a+b;
}
int minus(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;

}
int divide(int a,int b){
    return a/b;

}
int main(){
    int choose=0;
    int (*p)(int,int);
    int end=0;
    int a=0;
    int b=0;
    while(1){
        scanf("%d",&choose);
        switch(choose){
            case 1:
                scanf("%d %d",&a,&b);
                p=plus;
                printf("%d",p(a,b));
                break;
            case 2:
                scanf("%d %d",&a,&b);
                p=minus;
                printf("%d",p(a,b));
                break;
            case 3:
                scanf("%d %d",&a,&b);
                p=multiply;
                printf("%d",p(a,b));
                break;
            case 4:
                scanf("%d %d",&a,&b);
                p=divide;
                printf("%d",p(a,b));
                break;
            case 5:
                end=1;
                break;
        }
        if(end==1){
            break;
        }
    }
}