#include <stdio.h>
#include <stdbool.h>

int n, solutions = 0;
bool cols[20], diag1[40], diag2[40];

void backtrack(int row) {
    if (row == n) { solutions++; return; }
    for (int col = 0; col < n; col++) {
        int d1 = row - col + n, d2 = row + col;
        if (cols[col] || diag1[d1] || diag2[d2]) continue;
        cols[col] = diag1[d1] = diag2[d2] = true;
        backtrack(row + 1);
        cols[col] = diag1[d1] = diag2[d2] = false;
    }
}

int main() {
    scanf("%d", &n);
    backtrack(0);
    printf("%d\n", solutions);
    return 0;
}