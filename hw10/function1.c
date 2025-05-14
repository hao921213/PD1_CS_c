#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prefix {
    unsigned ip; 
    unsigned char len; 
    struct prefix* next; 
}prefix;

prefix* new_node(unsigned ip,unsigned char len,prefix* head){
    prefix* new_node = (struct prefix*)malloc(sizeof(struct prefix));
    new_node->ip = ip;
    new_node->len = len;
    new_node->next = head;
    return head; 
}
void input(int argc,char* argv , prefix** head, int* total_count) {
    printf("The file initializing the routing table: %s\n",argv[1]);
    printf("The file for extra insertion into the routing table: %s\n",argv[2]);
    printf("The file to delete specific IPs from the routing table: %s\n",argv[3]);
    printf("The file for IP lookups: %s\n",argv[4]);
    for(int i=1;i<argc;i++){
        FILE* file = fopen(argv[i], "r");
        char line[64];
        while (fgets(line, sizeof(line), file)) {
            // 分析 IP 和前綴長度（假設格式為 "192.168.0.0/24"）
            char ip_str[32];
            unsigned char len = 0;
            sscanf(line, "%[^/]/%hhu", ip_str, &len);

            // 將 IP 位址轉換為 32-bit 整數
            unsigned ip = 0;
            unsigned a, b, c, d;
            sscanf(ip_str, "%u.%u.%u.%u", &a, &b, &c, &d);
            ip = (a << 24) | (b << 16) | (c << 8) | d;
            // 創建新節點
            *head = new_node(ip,len,&head);
            (*total_count)++; // 計算前綴數量
        }

        fclose(file);

        if (strcmp(argv[i], "routing_table.txt") == 0) {
            printf("The total number of prefixes in the routing_table.txt is : %d.\n", *total_count);
        }
    }

}

