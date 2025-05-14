#include <stdio.h>
#include <string.h>
#include "hw7-3.h"
void ParsingData(char command[21],char* string1,char* string2){
    char temp1[21];
    char temp2[21];
    if(sscanf(command,"%20s = %20s",temp1,temp2)==2){
        strcpy(string1,temp1);
        strcpy(string2,temp2);
    }
    else{
        strcpy(string1,temp1);
        strcpy(string2," ");
    }
}