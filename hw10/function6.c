#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 從哈希表中刪除指定的前綴
void prefix_delete(struct hash_table* new_table, struct prefix* entry) {
    unsigned char key = get_key(entry->ip); // 計算雜湊鍵（基於 IP 的前 8 位）
    struct prefix** bucket = &new_table->table[key]; // 獲取對應槽的鏈結串列指針

    // 遍歷鏈結串列，查找並刪除目標節點
    while (*bucket) {
        // 如果找到匹配的 IP 和前綴長度
        if ((*bucket)->ip == entry->ip && (*bucket)->len == entry->len) {
            struct prefix* to_delete = *bucket;  // 暫存目標節點
            *bucket = (*bucket)->next;          // 更新鏈結串列指針，跳過目標節點
            free(to_delete);                    // 釋放刪除的節點記憶體
            return;                             // 刪除完成後返回
        }
        bucket = &(*bucket)->next; // 移動到鏈結串列的下一個節點
    }
}

// 從檔案中讀取前綴並刪除
void process_deleted_prefixes(struct hash_table* table, const char* filename) {
    FILE* file = fopen(filename, "r"); // 打開指定的文件
    if (!file) { // 如果文件無法打開
        printf("Error opening file: %s\n", filename); // 輸出錯誤信息
        return; // 返回，不繼續執行
    }

    char line[64]; // 緩衝區，用於存儲每行數據
    while (fgets(line, sizeof(line), file)) { // 循環讀取文件中的每行數據
        // 解析 IP 地址和前綴長度
        char ip_str[32];       // 用於存儲字符串格式的 IP 地址
        unsigned char len;     // 用於存儲前綴長度
        sscanf(line, "%[^/]/%hhu", ip_str, &len); // 解析 CIDR 格式（如 192.168.0.0/24）

        unsigned a, b, c, d;   // 用於存儲 IP 地址的 4 個段
        unsigned ip = 0;       // 初始化 IP 地址
        sscanf(ip_str, "%u.%u.%u.%u", &a, &b, &c, &d); // 解析字符串中的 IP 地址段
        ip = (a << 24) | (b << 16) | (c << 8) | d;    // 將段轉換為 32 位整數格式的 IP

        // 創建臨時前綴節點，只用於查找匹配節點
        struct prefix temp;
        temp.ip = ip;          // 設置 IP 地址
        temp.len = len;        // 設置前綴長度

        // 刪除哈希表中對應的前綴
        prefix_delete(table, &temp);
    }

    fclose(file); // 關閉文件
}
