#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    long long *arr = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    int maxLen = 1, curLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curLen++;
        } else {
            curLen = 1;
        }
        if (curLen > maxLen) maxLen = curLen;
    }

    printf("%d\n", maxLen);
    free(arr);
    return 0;
}