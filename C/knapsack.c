#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *weights = malloc(sizeof(int) * n);
    int *values = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &weights[i]);
    for (int i = 0; i < n; i++) scanf("%d", &values[i]);
    int capacity;
    scanf("%d", &capacity);

    int **dp = malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; i++) dp[i] = calloc(capacity + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                int take = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                if (take > dp[i][w]) dp[i][w] = take;
            }
        }
    }

    printf("%d\n", dp[n][capacity]);
    for (int i = 0; i <= n; i++) free(dp[i]);
    free(dp);
    free(weights);
    free(values);
    return 0;
}