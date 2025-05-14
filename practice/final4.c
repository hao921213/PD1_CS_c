#include <stdio.h>
int n=0;
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
int search(int n,node* head){
    node* p=head;
    int index=0;
    while(p){
        index++;
        if(index==n){
            return p->data;
        }
        p=p->next;
    }
    return -1;
}
node* change(int n1,int n2,node* head){
    node *ptr1=NULL;
    node *ptr2=NULL;
    node* p1=head;
    node* p2=head;
    while (p1 && p1->data != n1) {
        ptr1 = p1;
        p1 = p1->next;
    }
    while (p2 && p2->data != n2) {
        ptr2 = p2;
        p2 = p2->next;
    }
    if(ptr1){
        ptr1->next=p1->next;
    }
    else{
        head=p1->next;
    }

    if(ptr2){
        ptr2->next=p1;
    }
    else{
        head=p1;
    }
    p1->next=p2;

    return head;

}
void print_list(node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}
int main(){
    n=0;
    node* head=create_node(0);
    node* p=head;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        node* new_node=create_node(i);
        p->next=new_node;
        p=p->next;
    }
    head=head->next;
    // while(head){
    //     printf("%d->",head->data);
    //     head=head->next;
    // }
    // printf("null");

    int choose=0;
    int end=0;
    while(1){
        scanf("%d",&choose);
        switch(choose){
            case 1:
                int a=0;
                int b=0;
                scanf("%d %d",&a,&b);
                head=change(a,b,head);
                print_list(head);
                break;
            case 2:
                int num=0;
                scanf("%d",&num);
                printf("%d\n",search(num,head));
                break;
            case 3:
                end=1;
                break;
        }
        if(end==1){
            break;
        }
    }
}