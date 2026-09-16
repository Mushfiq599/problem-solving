#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long x, curSum, maxSum;
    scanf("%lld", &x);
    curSum = maxSum = x;

    for (int i = 1; i < n; i++) {
        scanf("%lld", &x);
        curSum = (x > curSum + x) ? x : curSum + x;
        if (curSum > maxSum) maxSum = curSum;
    }

    printf("%lld\n", maxSum);
    return 0;
}