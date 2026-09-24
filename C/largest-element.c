#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int k;
    scanf("%d", &k);

    int *used = calloc(n, sizeof(int));
    int result = 0;

    for (int t = 0; t < k; t++) {
        int maxVal = INT_MIN, maxIdx = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i] && arr[i] > maxVal) { maxVal = arr[i]; maxIdx = i; }
        }
        used[maxIdx] = 1;
        result = maxVal;
    }

    printf("%d\n", result);
    free(arr);
    free(used);
    return 0;
}