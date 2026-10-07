#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board;
string word;
int rows, cols;

bool dfs(int r, int c, int idx) {
    if (idx == (int)word.size()) return true;
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[idx]) return false;

    char temp = board[r][c];
    board[r][c] = '#';

    bool found = dfs(r + 1, c, idx + 1) || dfs(r - 1, c, idx + 1) ||
                 dfs(r, c + 1, idx + 1) || dfs(r, c - 1, idx + 1);

    board[r][c] = temp;
    return found;
}

int main() {
    cin >> rows >> cols;
    board.assign(rows, vector<char>(cols));
    for (auto &row : board) for (auto &c : row) cin >> c;
    cin >> word;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (dfs(r, c, 0)) { cout << "YES" << endl; return 0; }
        }
    }
    cout << "NO" << endl;
    return 0;
}