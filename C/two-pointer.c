#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long *h = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) scanf("%lld", &h[i]);

    int l = 0, r = n - 1;
    long long best = 0;
    while (l < r) {
        long long minH = h[l] < h[r] ? h[l] : h[r];
        long long area = minH * (r - l);
        if (area > best) best = area;
        if (h[l] < h[r]) l++;
        else r--;
    }
    printf("%lld\n", best);
    free(h);
    return 0;
}