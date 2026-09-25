#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 2) { printf("%d\n", n); return 0; }
    long long prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    printf("%lld\n", prev1);
    return 0;
}