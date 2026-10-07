#include <stdio.h>
#include <string.h>

char board[20][20];
char word[100];
int rows, cols, wlen;

int dfs(int r, int c, int idx) {
    if (idx == wlen) return 1;
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[idx]) return 0;

    char temp = board[r][c];
    board[r][c] = '#';

    int found = dfs(r + 1, c, idx + 1) || dfs(r - 1, c, idx + 1) ||
                dfs(r, c + 1, idx + 1) || dfs(r, c - 1, idx + 1);

    board[r][c] = temp;
    return found;
}

int main() {
    scanf("%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf(" %c", &board[i][j]);
    scanf("%s", word);
    wlen = strlen(word);

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (dfs(r, c, 0)) { printf("YES\n"); return 0; }
        }
    }
    printf("NO\n");
    return 0;
}