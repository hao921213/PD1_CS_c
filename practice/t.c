#include <stdio.h>

int main(){
        char input[100];
        char quoted[102];
        scanf("%s",input);
        snprintf(quoted, sizeof(quoted), "\"%s\"", input);
        printf(quoted);

}