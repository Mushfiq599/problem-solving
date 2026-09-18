#include <stdio.h>
#include <stdlib.h>

void reverseRange(long long *arr, int l, int r) {
    while (l < r) {
        long long tmp = arr[l]; arr[l] = arr[r]; arr[r] = tmp;
        l++; r--;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    long long *arr = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    int k;
    scanf("%d", &k);
    k %= n;

    reverseRange(arr, 0, n - 1);
    reverseRange(arr, 0, k - 1);
    reverseRange(arr, k, n - 1);

    for (int i = 0; i < n; i++) printf("%lld ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}