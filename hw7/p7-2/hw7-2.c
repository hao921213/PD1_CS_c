#include<stdio.h>
#include "hw7-2.h"
char input[21];
char* getUserInput(){
    fgets(input,sizeof(input),stdin);
    input[strcspn(input, "\n")] = '\0';
    return input;
}
void printAllInput(char command[51][21], int command_cnt){
    for(int i=0;i<command_cnt;i++){
        puts(command[i]);
    }
}