#include <bits/stdc++.h>
using namespace std;

int n, count_ = 0;
vector<bool> cols, diag1, diag2; // diag1 indexed by row-col+n, diag2 by row+col

void backtrack(int row) {
    if (row == n) { count_++; return; }
    for (int col = 0; col < n; col++) {
        int d1 = row - col + n, d2 = row + col;
        if (cols[col] || diag1[d1] || diag2[d2]) continue;
        cols[col] = diag1[d1] = diag2[d2] = true;
        backtrack(row + 1);
        cols[col] = diag1[d1] = diag2[d2] = false;
    }
}

int main() {
    cin >> n;
    cols.assign(n, false);
    diag1.assign(2 * n, false);
    diag2.assign(2 * n, false);
    backtrack(0);
    cout << count_ << endl;
    return 0;
}