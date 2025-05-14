#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node* create_node(int n){
    struct node* new_node =(node*)malloc(sizeof(struct node));
    new_node->data=n;
    new_node->next=NULL;
    return new_node;
}
int main(){
    struct node* head=create_node(0);
    struct node* dammy=head; 
    for(int i=0;i<10;i++){
        struct node* new_node=create_node(i);
        head->next=new_node;
        head=head->next;
    }
    dammy=dammy->next;
    while(dammy){
        printf("%d->",dammy->data);
        dammy=dammy->next;
    }
    printf("null");
}