#include <stdio.h>
int main(){
    struct test
    {
        int data;
        char name;
    };
    struct test part1={100,'a'};
    int *pt=&(part1.data); 
    printf("%d %c",*pt,*(pt+1));  
}