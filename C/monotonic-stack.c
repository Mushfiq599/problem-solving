#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long *arr = malloc(sizeof(long long) * n);
    long long *res = malloc(sizeof(long long) * n);
    int *stack = malloc(sizeof(int) * n);
    int top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        res[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[stack[top]] < arr[i]) {
            res[stack[top--]] = arr[i];
        }
        stack[++top] = i;
    }

    for (int i = 0; i < n; i++) printf("%lld ", res[i]);
    printf("\n");
    free(arr); free(res); free(stack);
    return 0;
}