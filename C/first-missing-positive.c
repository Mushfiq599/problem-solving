#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            int tmp = arr[arr[i] - 1];
            arr[arr[i] - 1] = arr[i];
            arr[i] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) { printf("%d\n", i + 1); free(arr); return 0; }
    }
    printf("%d\n", n + 1);
    free(arr);
    return 0;
}