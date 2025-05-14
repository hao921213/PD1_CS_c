#include <stdio.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* pre;
}node;

node* insert_a_node_dll(node* head,node*p){
    node* t=head;
    if(p==NULL)return head;
    if(head==NULL)return p;

    if(p->data<=head->data){
        p->next=head;
        head->pre=p;
        return p;
    }
    while(t->next!=NULL && t->next->data<p->data){
        t=t->next;
    }
    p->next=t->next;
    t->next=p;
    p->pre=t;
    if(t->next!=NULL)p->next->pre=p;
    return head;
}