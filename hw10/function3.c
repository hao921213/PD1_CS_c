#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prefix{
    unsigned ip;
    unsigned char len;
    struct prefix* next;
}prefix;

void length_distribution(struct prefix* head){
    int count[33]={0};
    prefix* p=head;
    while(p!=NULL){
        count[p->len]++;
        p=p->next;
    }
    for(int i=0;i<=32;i++){
        if(count[i]!=0){
            printf("the number of prefixes with prefix length %d = %d\n",i,count[i]);
        }
    }
}