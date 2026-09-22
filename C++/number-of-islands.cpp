#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int r, int c) {
    int rows = grid.size(), cols = grid[0].size();
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) return;
    grid[r][c] = 0; // mark visited
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for (auto &row : grid) for (auto &c : row) cin >> c;

    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                count++;
                dfs(grid, r, c);
            }
        }
    }
    cout << count << endl;
    return 0;
}