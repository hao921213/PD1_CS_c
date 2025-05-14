#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw7-1.h"
char temp[101];
int GameStart(){
    printf("Welcome to the game A = B, please select the level");
    scanf("%s",temp);
    if(strcmp(temp,"1")==0){
        return 1;
    }
    else if(strcmp(temp,"2")==0){
        return 2;
    }
    return -1;
}