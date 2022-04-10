#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
    int coins[3];
    int coinsSize = 3;
    int amount;
    int i;
    for (i = 0; i < 3; i++) {
        scanf("%d", &coins[i]);
    }
    scanf("%d", &amount);
    printf("%d", coinChange(coins, coinsSize, amount));
    return 0;
}
int coinChange(int* coins, int coinsSize, int amount) {
    //base case
    if (amount == 0)
        return 0;
    if (amount < 0)
        return -1;
    //定义一个备忘录，将备忘录中所有的值定为-66
    int memo[100 + 1];
    for (int i = 0; i < amount + 1; i++) {
        memo[i] = -66;
    }
    if (memo[amount] != -66)
        return memo[amount];
    int rel = 99999;
    for (int i = 0; i < coinsSize; i++) {
        int subProblem = coinChange(coins, coinsSize, amount - coins[i]);
        if (subProblem == -1)
            continue;
        rel = rel < subProblem + 1 ? rel : subProblem + 1;
    }
    memo[amount] = (rel == 99999) ? -1 : rel;
    return memo[amount];
}
