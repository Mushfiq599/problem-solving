#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int minOf3(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

int main() {
    char a[1001], b[1001];
    scanf("%s %s", a, b);
    int m = strlen(a), n = strlen(b);

    int **dp = malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) dp[i] = malloc(sizeof(int) * (n + 1));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + minOf3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }

    printf("%d\n", dp[m][n]);
    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);
    return 0;
}