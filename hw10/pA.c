#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prefix {
    unsigned ip; 
    unsigned char len;   
    struct prefix* next; 
} prefix;

prefix* new_node(unsigned ip,unsigned char len,prefix* head) {
    prefix* node=(prefix*)malloc(sizeof(prefix));
    node->ip=ip;
    node->len=len;
    node->next=head;
    return node;
}

// Function 1
void input(const char* filename, prefix** head, int* total_count) {
    FILE* file=fopen(filename,"r");
    char line[64];
    while (fgets(line,sizeof(line),file)){
        char ip_str[32];
        unsigned char len;
        if (sscanf(line,"%[^/]/%hhu",ip_str,&len)!=2) continue;
        unsigned a,b,c,d,ip=0;
        if (sscanf(ip_str,"%u.%u.%u.%u",&a,&b,&c,&d)==4) {
            ip=(a<<24)|(b<<16)|(c<<8)|d;
            *head = new_node(ip, len, *head);
            (*total_count)++;
        }
    }
    fclose(file);
}

// Function 2
void group_len(prefix* head, prefix* groups[33]) {
    for (int i=0;i<=32;i++) {
        groups[i]=NULL;
    }
    while(head){
        prefix* new_node=(prefix*)malloc(sizeof(prefix));
        new_node->ip=head->ip;
        new_node->len=head->len;
        new_node->next=groups[head->len];
        groups[head->len]=new_node;
        head=head->next;
    }
}

// Function 3
void length_distribution(prefix* groups[33]) {
    int count[33]={0};
    for (int i=0;i<=32;i++) {
        prefix* p=groups[i];
        while (p) {
            count[i]++;
            p = p->next;
        }
        if (count[i] > 0) {
            printf("the number of prefixes with prefix length %d = %d\n", i, count[i]);
        }
    }
}

// 主函數
int main(int argc, char* argv[]) {
    prefix* routing_table_head=NULL;
    int total_count = 0;

    printf("The file initializing the routing table: %s\n", argv[1]);
    printf("The file for extra insertion into the routing table: %s\n", argv[2]);
    printf("The file to delete specific IPs from the routing table: %s\n", argv[3]);
    printf("The file for IP lookups: %s\n\n", argv[4]);

    // Function 1
    input(argv[1], &routing_table_head, &total_count);
    printf("The total number of prefixes in the routing_table.txt is : %d.\n\n", total_count);

    // 分組
    prefix* groups[33];
    group_len(routing_table_head, groups);

    // 統計並輸出
    length_distribution(groups);

    return 0;
}
