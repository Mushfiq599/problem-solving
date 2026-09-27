#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[1001], b[1001];
    scanf("%s %s", a, b);
    int m = strlen(a), n = strlen(b);

    int **dp = malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) dp[i] = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    printf("%d\n", dp[m][n]);
    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);
    return 0;
}