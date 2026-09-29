#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> weights(n), values(n);
    for (auto &w : weights) cin >> w;
    for (auto &v : values) cin >> v;
    int capacity; cin >> capacity;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    cout << dp[n][capacity] << endl;
    return 0;
}