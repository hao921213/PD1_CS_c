#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prefix{
    unsigned ip;
    unsigned char len;
    struct prefix* next;
}prefix;

prefix* new_node(unsigned ip,unsigned char len,prefix* head){
    prefix* new_node = (struct prefix*)malloc(sizeof(struct prefix));
    new_node->ip = ip;
    new_node->len = len;
    new_node->next=head;
    return new_node;
}

void group_len(struct prefix** head, struct prefix* groups[33]){
    for(int i=0;i<32;i++){
        groups[i]==NULL;
    }
    prefix* p=head;
    while(p!=NULL){
        prefix* new_node = (prefix*)malloc(sizeof(prefix));
        new_node->ip = p->ip;
        new_node->len = p->len;
        new_node->next = groups[p->len]; 
        groups[p->len] = new_node;
        p = p->next;
    }

}