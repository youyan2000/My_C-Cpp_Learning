#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    int i, j;
    int coins[] = {1, 5, 10, 20, 50, 100};
    int coin_count = 6;
    
    printf("请输入金额：");
    if (scanf_s("%d", &x) != 1 || x < 0) {
        printf("输入无效！\n");
        return 1;
    }
    
    if (x > 100000) {
        printf("金额太大，可能导致内存溢出！\n");
        return 1;
    }
    
    // 动态分配数组，避免栈溢出
    long long *dp = (long long *)calloc(x + 1, sizeof(long long));
    if (dp == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }
    
    dp[0] = 1;  // 金额为0时有一种方法
    
    // 计算组合数
    for (i = 0; i < coin_count; i++) {
        int coin = coins[i];
        for (j = coin; j <= x; j++) {
            dp[j] += dp[j - coin];
        }
    }
    
    printf("一共有%lld种方法\n", dp[x]);
    
    // 清理内存
    free(dp);
    
    // 暂停查看结果
    system("pause");
    return 0;
}
