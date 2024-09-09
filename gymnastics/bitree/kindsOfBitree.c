//
// Created by yanqi on 2024/9/9.
//
#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);
    int dp[size + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= size; ++i) {
        dp[i] = 0;
        // 计算所有情况
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j -1];
        }
    }
    printf("%d", dp[size]);
}