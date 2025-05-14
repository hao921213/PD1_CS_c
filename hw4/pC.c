#include <stdio.h>
#include <float.h>
#include <math.h>
void print_bit_pattern(float number) {
    int *bit_pattern = (int*)&number;
    for (int i = 31; i >= 0; i--) {
        printf("%d", (*bit_pattern >> i) & 1);
    }
    printf("\n");
}

int main() {
    // 正規化浮點數
    float max_normalized = FLT_MAX;
    float min_normalized = FLT_MIN;
    float neg_max_normalized = -FLT_MAX;
    float neg_min_normalized = -FLT_MIN;

    // 非正規化浮點數
    float max_denormalized = (float)((1 << 23) - 1) * FLT_MIN / (1 << 23); // 最大非正規化數值
    float min_denormalized = FLT_MIN / (1 << 23);                          // 最小非正規化數值
    float neg_max_denormalized = -max_denormalized;                        // 最大非正規化負數
    float neg_min_denormalized = -min_denormalized;                        // 最小非正規化負數

    // 輸出正規化浮點數
    printf("最大正規化浮點數 (FLT_MAX): %e\n", max_normalized);
    printf("最大正規化浮點數的二進位: ");
    print_bit_pattern(max_normalized);

    printf("最小正規化浮點數 (FLT_MIN): %e\n", min_normalized);
    printf("最小正規化浮點數的二進位: ");
    print_bit_pattern(min_normalized);

    printf("最大正規化負浮點數 (-FLT_MAX): %e\n", neg_max_normalized);
    printf("最大正規化負浮點數的二進位: ");
    print_bit_pattern(neg_max_normalized);

    printf("最小正規化負浮點數 (-FLT_MIN): %e\n", neg_min_normalized);
    printf("最小正規化負浮點數的二進位: ");
    print_bit_pattern(neg_min_normalized);

    // 輸出非正規化浮點數
    printf("最大非正規化浮點數: %e\n", max_denormalized);
    printf("最大非正規化浮點數的二進位: ");
    print_bit_pattern(max_denormalized);

    printf("最小非正規化浮點數: %e\n", min_denormalized);
    printf("最小非正規化浮點數的二進位: ");
    print_bit_pattern(min_denormalized);

    printf("最大非正規化負浮點數: %e\n", neg_max_denormalized);
    printf("最大非正規化負浮點數的二進位: ");
    print_bit_pattern(neg_max_denormalized);

    printf("最小非正規化負浮點數: %e\n", neg_min_denormalized);
    printf("最小非正規化負浮點數的二進位: ");
    print_bit_pattern(neg_min_denormalized);


    float nan=NAN;
    int *f_nan=(int*)&nan;
    printf("nan值的二進位:");
    for(int i=31;i>=0;i--){
        printf("%d",(*f_nan>>i)&1);
    }
    printf("\n");
    float inf=INFINITY;
    int *f_inf=(int*)&inf;
    printf("inf值的二進位:");
    for(int i=31;i>=0;i--){
        printf("%d",(*f_inf>>i)&1);
    }

    return 0;
}
