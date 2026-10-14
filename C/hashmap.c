#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long *arr = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    long long k;
    scanf("%lld", &k);

    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) count++;
        }
    }
    printf("%lld\n", count);
    free(arr);
    return 0;
}