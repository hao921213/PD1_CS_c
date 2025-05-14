//create_node(return node*) 順順序輸出
#include <stdio.h>
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
int main(){
    node* damp=create_node(0);
    node* head=damp;
    for(int i=0;i<10;i++){
        damp->next=create_node(i);
        damp=damp->next;
    }
    head=head->next;
    for(;head!=NULL;head=head->next){
        printf("%d->",head->data);
    }
}
