#include <stdio.h>

int nums[10], used[10], current[10], n;

void backtrack(int depth) {
    if (depth == n) {
        printf("[");
        for (int i = 0; i < n; i++) printf("%d%s", current[i], i + 1 < n ? "," : "");
        printf("] ");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = 1;
        current[depth] = nums[i];
        backtrack(depth + 1);
        used[i] = 0;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    backtrack(0);
    printf("\n");
    return 0;
}