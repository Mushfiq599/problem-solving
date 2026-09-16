#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long *arr = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    int insertPos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) arr[insertPos++] = arr[i];
    }
    while (insertPos < n) arr[insertPos++] = 0;

    for (int i = 0; i < n; i++) printf("%lld ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}