#include <stdio.h>
#include <string.h>
int main(){
    int n=0;
    char day_str[10];
    scanf("%2d",&n);
    printf("%d\n",n);
    sprintf(day_str, "%2d", n);
    puts(day_str);
}