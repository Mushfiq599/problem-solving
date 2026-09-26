#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int numCoins;
    scanf("%d", &numCoins);
    int *coins = malloc(sizeof(int) * numCoins);
    for (int i = 0; i < numCoins; i++) scanf("%d", &coins[i]);
    int amount;
    scanf("%d", &amount);

    int *dp = malloc(sizeof(int) * (amount + 1));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) dp[i] = INT_MAX;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < numCoins; j++) {
            int coin = coins[j];
            if (coin <= i && dp[i - coin] != INT_MAX) {
                if (dp[i - coin] + 1 < dp[i]) dp[i] = dp[i - coin] + 1;
            }
        }
    }

    printf("%d\n", dp[amount] == INT_MAX ? -1 : dp[amount]);
    free(coins);
    free(dp);
    return 0;
}