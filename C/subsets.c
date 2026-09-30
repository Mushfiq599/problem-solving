#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[20];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int total = 1 << n; // 2^n subsets
    for (int mask = 0; mask < total; mask++) {
        printf("[");
        int first = 1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (!first) printf(",");
                printf("%d", nums[i]);
                first = 0;
            }
        }
        printf("] ");
    }
    printf("\n");
    return 0;
}