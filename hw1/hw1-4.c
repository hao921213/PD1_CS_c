#include <stdio.h>
int main(){

        int a=0;
        int b=0;
        char operate;

        scanf("%d%c%d",&a,&operate,&b);

        int plus=(operate=='+');
        int minus=(operate=='-');
        int multiply=(operate=='*');

        printf("%d\n",(a+b)*plus+(a-b)*minus+(a*b)*multiply);

}