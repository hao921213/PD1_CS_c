#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定義prefix
typedef struct prefix {
    unsigned ip;               // 32 位 IP 地址
    unsigned char len;         // 前綴長度
    struct prefix* next;       // 指向下一個前綴的指針
} prefix;

// 定義hash_table
typedef struct hash_table {
    struct prefix* table[256]; // 每個index是單向鏈結串列
} hash_table;

// 創建hash_table並初始化
hash_table* create_hash_table() {
    hash_table* new_table = (hash_table*)malloc(sizeof(hash_table));
    for (int i = 0; i < 256; i++) {
        new_table->table[i] = NULL;
    }
    return new_table;
}

// 計算hash_key（前八位）
unsigned char hash_key(unsigned ip) {
    return (ip >> 24) & 0xFF;
}

//找到比entry大的位置並插入該節點的前面
void insert_into_hash_table(hash_table* table, prefix* entry) {
    unsigned char key = hash_key(entry->ip);
    prefix** bucket = &table->table[key];
    while (*bucket && (*bucket)->ip < entry->ip) {
        bucket = &(*bucket)->next;
    }
    entry->next = *bucket;
    *bucket = entry;
}

// 從文件讀取前綴到鏈結串列
prefix* read_prefixes(const char* filename, int* total_count) {
    FILE* file=fopen(filename,"r");
    prefix* head=NULL;
    char line[64];
    *total_count=0;
    while (fgets(line,sizeof(line),file)) {
        char ip_str[32];
        unsigned char len;
        if (sscanf(line,"%[^/]/%hhu",ip_str, &len)!=2) continue;
        unsigned a, b, c, d, ip = 0;
        if (sscanf(ip_str,"%u.%u.%u.%u",&a,&b,&c,&d)==4) {
            ip =(a<<24)|(b<<16)|(c<<8)|d;
            prefix* new_prefix=(prefix*)malloc(sizeof(prefix));
            new_prefix->ip=ip;
            new_prefix->len=len;
            new_prefix->next=head;
            head=new_prefix;
            (*total_count)++;
        }
    }
    fclose(file);
    return head;
}

// 將前綴分組（Function 2: group_len）
void group_len(prefix* head, prefix* groups[33]) {
    for (int i = 0; i <= 32; i++) {
        groups[i] = NULL;
    }

    while (head) {
        prefix* next = head->next;
        head->next = groups[head->len];
        groups[head->len] = head;
        head = next;
    }
}

// 計算長度分佈（Function 3: length_distribution）
void length_distribution(prefix* groups[33]) {
    for (int i = 0; i <= 32; i++) {
        int count = 0;
        prefix* current = groups[i];
        while (current) {
            count++;
            current = current->next;
        }
        if (count > 0) {
            printf("The number of prefixes with prefix length %d = %d\n", i, count);
        }
    }
}

//Function 4:
void segment(prefix* groups[33], hash_table* hash_tables[33]) {
    for (int i = 0; i <= 32; i++) {
        // 如果對應prefix長度的鏈結串列為NULL
        if (!groups[i]) {
            hash_tables[i] = NULL;  // 將對應的Hash_table設為 NULL
            continue;               //continue不建立hash_table
        }
        hash_tables[i] = create_hash_table();// 若prefix有值則創建一個對應的hash_table
        prefix* current = groups[i];//建立一個current去暫存group的第一個
        while (current) {
            prefix* next = current->next; // 保存當前節點的下一個節點pointer
            current->next = NULL;         // 斷開當前節點與鏈結串列的連結
            insert_into_hash_table(hash_tables[i], current); // 插入當前節點到hash_table
            current = next;               // 移動到下一個節點
        }
    }
}


// Function 5
void prefix_insert(hash_table* hash_tables[33], const char* filename) {
    int total_count = 0; // 用於存儲讀取的prefix數量，初始化為 0
    prefix* inserted_prefixes = read_prefixes(filename, &total_count);
    // 從filename中讀取prefix，返回一個鏈結串列，並將讀取的prefix總數存在total_count中
    while (inserted_prefixes) {
        prefix* next = inserted_prefixes->next; // 保存當前節點的下一個節點pointer
        insert_into_hash_table(hash_tables[inserted_prefixes->len], inserted_prefixes);
        //根據讀到的資料利用insert_into_hash_table將inserted_prefixes將插入inserted_prefixes->len相對應的hash_table
        inserted_prefixes = next;// 移動到下一個pointer
    }
}


//Function 6
void prefix_delete(hash_table* hash_tables[33], const char* filename) {
    int total_count=0; // 用於存儲讀取的prefix數量，初始化為 0
    prefix* deleted_prefixes = read_prefixes(filename, &total_count);
    // 從filename中讀取prefix，返回一個鏈結串列，並將讀取的prefix總數存在total_count中
    while (deleted_prefixes) {
        prefix* next = deleted_prefixes->next; // 保存當前節點的下一個節點pointer
        unsigned char key = hash_key(deleted_prefixes->ip);// 找到當前prefix的hash_key

        // 獲取當前prefix len對應的hash_table，並找到對應的hash_table的table
        prefix** bucket = &hash_tables[deleted_prefixes->len]->table[key];
        while (*bucket) {
            if ((*bucket)->ip == deleted_prefixes->ip) { 
                // 如果找到目標pointer
                prefix* to_delete = *bucket; 
                // 暫存目標節點的pointer
                *bucket = (*bucket)->next; 
                // 從鏈結串列中移除目標pointer
                free(to_delete); 
                break; 
                // 跳出循環
            }
            bucket = &(*bucket)->next; 
            // 移動到下一個節點繼續找
        }
        free(deleted_prefixes); 
        deleted_prefixes = next; 
        // 移動到下一個需要刪除的節點
    }
}


// Function 7
void search(hash_table* hash_tables[33], const char* filename) {
    FILE* file = fopen(filename, "r");
    char line[32]; 
    // 用於存儲從文件中讀取的每行內容
    while (fgets(line, sizeof(line), file)) {
        unsigned a, b, c, d, ip = 0; //a,b,c,d用於存儲分解的ip

        // 將每行ip拆成為 4 個無符號整數 a, b, c, d
        if (sscanf(line, "%u.%u.%u.%u", &a, &b, &c, &d) == 4) {
            ip = (a << 24) | (b << 16) | (c << 8) | d;

            int found = 0; 
            // 標記是否找到相同的prefix，初始為0
            for (int i = 32; i >= 0; i--) {
                if (!hash_tables[i]) continue; 
                // 如果當前prefix的hash_table為空，跳過

                unsigned char key = hash_key(ip); 
                // 取得hash_key(前8位)

                prefix* bucket = hash_tables[i]->table[key]; 
                //取得相對應的table

                while (bucket) {
                    if (bucket->ip == ip) { 
                        // 如果匹配成功
                        printf("Search successful: %u.%u.%u.%u/%d\n", a, b, c, d, i);
                        found = 1; 
                        // 標記已找到
                        break;
                    }
                    bucket = bucket->next; 
                    // 移動到鏈結串列的下一個point
                }
                if (found) break; 
                // 如果已找到，結束循環
            }

            // 如果都沒找到，輸出失敗消息
            if (!found) {
                printf("Search failed for IP: %u.%u.%u.%u\n", a, b, c, d);
            }
        }
    }
    fclose(file); 
    // 關閉file
}


// 主函數
int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <routing_table.txt> <inserted_prefix.txt> <deleted_prefix.txt> <trace_file.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 讀取並分組路由表
    int total_count = 0;
    prefix* routing_table = read_prefixes(argv[1], &total_count);
    printf("The total number of prefixes in the routing_table.txt is : %d\n", total_count);

    prefix* groups[33];
    group_len(routing_table, groups);
    length_distribution(groups);

    // 創建哈希表並分段
    hash_table* hash_tables[33];
    segment(groups, hash_tables);

    // 插入新前綴
    prefix_insert(hash_tables, argv[2]);

    // 刪除指定前綴
    prefix_delete(hash_tables, argv[3]);

    // 搜尋 IP
    search(hash_tables, argv[4]);

    return 0;
}
