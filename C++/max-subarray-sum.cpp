#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;

    long long maxSum = arr[0], curSum = arr[0];
    for (int i = 1; i < n; i++) {
        curSum = max(arr[i], curSum + arr[i]);
        maxSum = max(maxSum, curSum);
    }
    cout << maxSum << endl;
    return 0;
}