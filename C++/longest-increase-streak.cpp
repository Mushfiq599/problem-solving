#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int maxLen = 1, curLen = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curLen++;
        } else {
            curLen = 1;
        }
        maxLen = max(maxLen, curLen);
    }

    cout << maxLen << endl;
    return 0;
}