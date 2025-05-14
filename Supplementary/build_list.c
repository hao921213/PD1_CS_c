#include <stdio.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* create_node(int n){
    node* new_node;
    new_node->data=n;
    new_node->next=NULL;
    return new_node;
}
node* insert_node(node* head,node* p){
    node* t=head;
    if(p==NULL)return head;
    if(head==NULL)return p;
    if(p->next<=head->next){
        p->next=head;
        return p;
    }
    while(t->next!=NULL && t->next->data<p->data){
        t->next;
    }
    p->next=t->next;
    t->next=p;
    return head;
}
node* build_a_list(int data[],int n){
    node* head=NULL;
    node* p;
    for(int i=0;i<n;i++){
        p=create_node(data[i]);
        head=insert_node(head,p);
    }
    return head;
}
int count_list(node* head){
    node* t=head;
    int count=0;
    while(t!=NULL){
        count++;
        t=t->next;
    }
    return count;
}
node* search_node(int n,node* head){
    node* t=head;
    while(t!=NULL){
        if(t->data!=n){
            t=t->next;
        }
    }
    return t;
}
node* merge_two_listA(node* h1,node* h2){
    node* t;
    node* tail;
    node* newh=NULL;
    while(h1!=NULL && h2!=NULL){
        if(h1->data > h2->data){
            t=h1;
            h1=h1->next;
            t->next=NULL;
        }
        else{
            t=h2;
            h2=h2->next;
            t->next=NULL;
        }
        if(newh==NULL){
            newh=t;
            tail=t;
        }
        else{
            tail->next=t;
            tail=t;
        }
    }
    if(h1!=NULL){
        tail->next=h1;
    }
    if(h2!=NULL){
        tail->next=h2;
    }
    return newh;
}
node* merge_two_listB(node* h1,node* h2){//把h2合併在h1裡面
    node* t;
    while(h1!=NULL){
        t=h1;
        t->next=NULL;
        h1=h1->next;
        h2=insert_node(h2,t);
    }
    return h2;
}

node*duplicate(node* h){//複製一個數據一樣但在不同記憶體的list
    node* t;
    node* newh=NULL;
    node* tail;
    while(h!=NULL){
        t=create_node(h->data);
        if(newh==NULL){
            newh=t;
            tail=t;
        }
        else{
            tail->next=t;
            tail=tail->next;
        }
        h=h->next;
    }
    return newh;
}