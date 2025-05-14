#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* insert_a_node(node* head,node* p){
    node *t=head;

    if(head==NULL)return p;//如果沒有head回傳p當作第一個節點
    if(p==NULL)return head;//如果沒有p代表沒有insert node，直接回傳head

    if(p->data<=head->data){//如果insert node在第一個
        p->next=head;
        return p;
    }
    while(t->next!=NULL && (t->next)->data<p->data){
        t=t->next;
    }
    p->next=t->next;//insert
    t->next=p;
    return head;
}

void insert_a_node_no_returnA(node **head,node* p){
    node* t=*head;

    if(*head==NULL) *head=p; return;
    if(p==NULL)return;
    if(p->data<=(*head)->data){//注意括號(優先序問題)
        p->next=*head;
        *head=p;
    }
    while(t->next!=NULL && t->next->data<p->data){
        t=t->next;
    }
    p->next=t->next;
    t->next=p;
    return;
}

void insert_a_node_no_returnB(node** head,node* p){
    node** x=head;
    if(p==NULL)return;
    while((*x)!=NULL && (*x)->data<p->data){
        x=&((*x)->next);
    }
    p->next=(*x);
    (*x)=p;
    return;
}