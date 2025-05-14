#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//建立struct裡面包含ip(32bit的資料),len(prefix len),next(單向鏈結串列)
typedef struct prefix{
    unsigned ip;
    unsigned char len;
    struct prefix* next;
}prefix;
//建立hash_table去儲存前8個bit的共256(2的8次方)個prefix陣列
typedef struct hash_table{
    struct prefix* table[256];
}hash_table;

// 插入prefix到hash_table中，保持鏈結串列按升序排列
void prefix_insert(struct hash_table* new_table, struct prefix* new_entry) {
    unsigned char key = hash_key(new_entry->ip); // hash_table_key
    struct prefix** bucket = &new_table->table[key];//利用二次指標去儲存指標
    // 插入到升序鏈結串列中
    while (*bucket && (*bucket)->ip < new_entry->ip) {//找到小於new_entry->ip並替換二次只指向的指標
        bucket = &(*bucket)->next;
    }
    new_entry->next = *bucket; // 插入到當前位置
    *bucket = new_entry;
}

// 從檔案讀取前綴並插入到雜湊表
void process_inserted_prefixes(struct hash_table* table, const char* filename) {
    FILE* file = fopen(filename, "r");//開啟檔案
    char line[64];//創建一個line，去儲存get到的內容
    while (fgets(line, sizeof(line), file)) {//利用for迴圈去取得每一行直到NULL
        char ip_str[32];
        unsigned char len;
        sscanf(line, "%[^/]/%hhu", ip_str, &len);//利用sscnaf()去取得/前的ip存在ip_str內，將/後的存在len內
        unsigned a, b, c, d;
        unsigned ip = 0;
        sscanf(ip_str, "%u.%u.%u.%u", &a, &b, &c, &d);//用a,b,c,d去儲存ip中利用.分開
        ip = (a << 24) | (b << 16) | (c << 8) | d;//用bit位移跟or的方式將a,b,c,d串在一起
        // 創建新的prefix節點
        struct prefix* new_entry = (struct prefix*)malloc(sizeof(struct prefix));
        new_entry->ip = ip;
        new_entry->len = len;
        new_entry->next = NULL;
        // 插入到hash_table
        prefix_insert(table, new_entry);
    }
    fclose(file);
}
