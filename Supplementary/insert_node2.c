#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* create_node(int n){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=n;
    new_node->next=NULL;
    return new_node; 
}
void insert_node(node** head,node* p){
    node* new=*head;
    if(*head==NULL){
        *head=p;
        return;
    }
    
    if(p==NULL)return;
    if((*head)->data > p->data){
        p->next=*head;
        *head=p;
        return;
    }
    while(new->next!=NULL && new->next->data < p->data){
        new=new->next;
    }
    p->next=new->next;
    new->next=p;
}
void insert_node2(node** head,node* p){
    node** new=head;    
    if(p==NULL)return;

    while((*new)!=NULL && (*new)->data<p->data){
        new=&((*new)->next);
    }
    p->next=(*new);
    (*new)=p;
}
int main(){
    int num[]={10,5,7,2,8,1};
    node* head=NULL;
    for(int i=0;i<6;i++){
        node *new=create_node(num[i]);
        insert_node2(&head,new);
    }
    node* damp=head;
    for(;damp!=NULL;damp=damp->next){
        printf("%d ",damp->data);
    }
}
