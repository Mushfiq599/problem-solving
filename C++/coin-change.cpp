#include <bits/stdc++.h>
using namespace std;

int main() {
    int numCoins; cin >> numCoins;
    vector<int> coins(numCoins);
    for (auto &c : coins) cin >> c;
    int amount; cin >> amount;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << (dp[amount] == INT_MAX ? -1 : dp[amount]) << endl;
    return 0;
}