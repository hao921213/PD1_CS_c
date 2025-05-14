#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 定義前綴結構，用於存儲 IP 地址、前綴長度以及鏈結串列指針
typedef struct prefix {
    unsigned ip;               // 32 位的 IP 地址
    unsigned char len;         // 前綴長度
    struct prefix* next;       // 指向下一個前綴的指針
} prefix;

// 定義哈希表結構，包含 256 個指向鏈結串列的指針
typedef struct hash_table {
    struct prefix* table[256]; // 每個槽存儲一個鏈結串列
} hash_table;

// 根據 LPM (Longest Prefix Match) 原則搜尋目標 IP
void search(struct hash_table* new_table, unsigned ip) {
    // 從前綴長度 32 開始向下嘗試匹配，直到 0
    for (int len = 32; len >= 0; len--) {
        unsigned char key = hash_key(ip); // 計算雜湊鍵（基於 IP 的前 8 位）
        struct prefix* bucket = new_table->table[key]; // 獲取對應槽的鏈結串列

        // 遍歷鏈結串列以查找匹配的前綴
        while (bucket) {
            // 如果找到與當前前綴長度匹配的節點
            if (bucket->len == len) {
                // 打印匹配結果
                printf("Search successful: %u.%u.%u.%u/%d\n",
                       (bucket->ip >> 24) & 0xFF, // 提取 IP 的最高 8 位
                       (bucket->ip >> 16) & 0xFF, // 提取 IP 的次高 8 位
                       (bucket->ip >> 8) & 0xFF,  // 提取 IP 的次低 8 位
                       bucket->ip & 0xFF,         // 提取 IP 的最低 8 位
                       bucket->len);              // 打印前綴長度
                return; // 成功匹配後退出函數
            }
            bucket = bucket->next; // 移動到鏈結串列的下一個節點
        }
    }
    // 如果所有前綴長度都未匹配，打印搜尋失敗消息
    printf("Search failed for IP: %u.%u.%u.%u\n",
           (ip >> 24) & 0xFF, // 提取 IP 的最高 8 位
           (ip >> 16) & 0xFF, // 提取 IP 的次高 8 位
           (ip >> 8) & 0xFF,  // 提取 IP 的次低 8 位
           ip & 0xFF);        // 提取 IP 的最低 8 位
}
