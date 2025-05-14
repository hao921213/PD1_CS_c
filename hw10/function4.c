#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定義一個 `prefix` 結構，用於存儲每個 IP 前綴的數據
typedef struct prefix {
    unsigned ip;               // 32位IP地址
    unsigned char len;         // 前綴長度
    struct prefix* next;       // 指向下一個前綴的指針，用於單向鏈表
} prefix;

// 定義一個 `hash_table` 結構，儲存256個 `prefix` 鏈表指針
typedef struct hash_table {
    struct prefix* table[256]; // 哈希表，包含256個槽，每個槽存一個鏈表
} hash_table;

// 建立一個哈希表並初始化每個槽為NULL
struct hash_table* create_hash_table() {
    struct hash_table* new_table = (struct hash_table*)malloc(sizeof(struct hash_table)); // 分配內存
    for (int i = 0; i < 256; i++) {
        new_table->table[i] = NULL; // 初始化每個槽為NULL
    }
    return new_table; // 返回新建的哈希表
}

// 將一個 `prefix` 節點插入到哈希表中的對應槽中
void insert_into_hash_table(struct hash_table* new_table, struct prefix* head) {
    unsigned char key = get_key(head->ip); // 根據 IP 地址計算哈希鍵
    head->next = new_table->table[key];    // 將節點插入對應槽的鏈表頭部
    new_table->table[key] = head;          // 更新槽的指針為新節點
}

// 將某一長度的前綴鏈表分組到哈希表中
struct hash_table* group_to_hash_table(struct prefix* group) {
    struct hash_table* table = create_hash_table(); // 創建一個新哈希表
    struct prefix* current = group;                // 遍歷該長度的鏈表
    while (current != NULL) {
        insert_into_hash_table(table, current);    // 插入到哈希表
        current = current->next;                  // 移動到下一個節點
    }
    return table; // 返回構建好的哈希表
}

// 從IP地址的前8個bit提取哈希鍵
unsigned char get_key(unsigned ip) {
    return (ip >> 24) & 0xFF; // 提取最高的8位作為哈希鍵
}

// 將分組的前綴鏈表轉換成多個哈希表並存儲
void segment(struct prefix* groups[33], struct hash_table* table[33]) {
    for (int i = 0; i <= 32; i++) { // 遍歷所有前綴長度
        if (groups[i] != NULL) {
            table[i] = group_to_hash_table(groups[i]); // 如果該長度的鏈表不為空，分組到哈希表
        } else {
            table[i] = NULL; // 如果該長度的鏈表為空，對應的哈希表設為NULL
        }
    }
}
