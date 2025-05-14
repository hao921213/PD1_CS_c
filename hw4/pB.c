#include <stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    float *f=(float*)&num;
    printf("%.23e",*f);
}