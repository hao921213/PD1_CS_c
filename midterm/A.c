#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 检查字符串是否是回文
bool is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// 找到所有可以删除使数字成为回文的位
void find_deletable_positions(char num[]) {
    int len = strlen(num);
    bool has_palindrome = false;

    for (int i = 0; i < len; i++) {
        char new_num[len]; // 存储删除一个字符后的新字符串
        int k = 0;

        // 构建删除第i位后的字符串
        for (int j = 0; j < len; j++) {
            if (j != i) {
                new_num[k++] = num[j];
            }
        }
        new_num[k] = '\0'; // 结束字符串

        // 检查新字符串是否是回文
        if (is_palindrome(new_num)) {
            printf("%d ", i + 1); // 打印位置，1索引
            has_palindrome = true;
        }
    }

    if (!has_palindrome) {
        printf("Impossible");
    }
    printf("\n");
}

int main() {
    char num[100]; 
    scanf("%s", num);

    find_deletable_positions(num);
    return 0;
}
