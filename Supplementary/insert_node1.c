#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
node* create_node(int n){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=n;
    new_node->next=NULL;
    return new_node; 
}
node* insert_node(node* head,node* p){
    if(p==NULL)return head;
    if(head==NULL)return p;
    node *t=head;
    if(t->data>p->data){
        p->next=t;
        return p;        
    }
    while(t->next!=NULL && t->next->data<p->data){
        t=t->next;
    }
    p->next=t->next;
    t->next=p;
    return head;
}
int main(){
    int num[]={10,5,7,2,8,1};
    node* head=NULL;
    for(int i=0;i<6;i++){
        node *new=create_node(num[i]);
        head=insert_node(head,new);
    }
    node* damp=head;
    for(;damp!=NULL;damp=damp->next){
        printf("%d ",damp->data);
    }
}
