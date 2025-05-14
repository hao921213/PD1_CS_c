#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int val;
    struct node* next;
};
struct node* create_node(int num){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=num;
    new_node->next=NULL;
    return new_node;
}
int main(){
    struct node* first=create_node(0);
    struct node* ptr=first;
    struct node* pre=NULL;
    srand( time(NULL) );
    for(int i=0;i<10;i++){
        int x = rand() % 10 + 1;
        struct node* new=create_node(x);
        first->next=new;
        first=first->next;
    }
    for(struct node* t=ptr->next;t!=NULL;t=t->next){
        printf("%d ",t->val);
    }
    printf("\n");

    struct node* even=create_node(0);
    struct node* even_head=even;

    ptr = ptr->next; 
    first = ptr;    

    for(;ptr!=NULL;){
        if(ptr->val%2==0){
            struct node* new_even=create_node(ptr->val);
            even->next=new_even;
            even=even->next;
            if(pre){
                pre->next=ptr->next;
            }
            else{
                first = ptr->next;
            }
            ptr=ptr->next;
        }
        else{
            pre=ptr;
            ptr=ptr->next;
        }
    }
    for(struct node* ptr=first;ptr!=NULL;ptr=ptr->next){
        printf("%d ",ptr->val);
    }
    printf("\n");
    for(struct node* ptr=even_head->next;ptr!=NULL;ptr=ptr->next){
        printf("%d ",ptr->val);
    }
}