//create_node(return node*) 逆順序輸出
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

node* create_node1(node* head,int num){
    node* p=(node*)malloc(sizeof(struct node));
    p->data=num;
    p->next=head;
    return p;
}
int main(){
    node* head=(node*)malloc(sizeof(struct node));
    head->next=NULL;
    for(int i=0;i<10;i++){
        head=create_node1(head,i);
    }
    for(node* ptr=head;ptr->next!=NULL;ptr=ptr->next){
        printf("%d->",ptr->data);
    }
    printf("null");
}