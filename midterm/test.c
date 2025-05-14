#include <stdio.h>
int main(){
    int x[2]={1, 8};
    int *p=&x[0];x[0]=1; x[1]=8; x[0] = *p++  + 1;   
        printf("x[0]=%d, x[1]=%d, *p=%d, p=%p\n", x[0], x[1], *p, p); 
    p=&x[0];x[0]=1; x[1]=8; x[0] = (*p)++ + 1;   
        printf("x[0]=%d, x[1]=%d, *p=%d, p=%p\n", x[0], x[1], *p, p); 
    p=&x[0];x[0]=1; x[1]=8; x[0] = *++p  + 1;   
        printf("x[0]=%d, x[1]=%d, *p=%d, p=%p\n", x[0], x[1], *p, p); 
    p=&x[0];x[0]=1; x[1]=8; x[0] = ++*p  + 1;   
        printf("x[0]=%d, x[1]=%d, *p=%d, p=%p\n", x[0], x[1], *p, p); 
}