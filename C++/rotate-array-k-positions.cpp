#include <bits/stdc++.h>
using namespace std;

void reverseRange(vector<long long> &arr, int l, int r) {
    while (l < r) { swap(arr[l], arr[r]); l++; r--; }
}

int main() {
    int n; cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;
    int k; cin >> k;
    k %= n;

    reverseRange(arr, 0, n - 1);
    reverseRange(arr, 0, k - 1);
    reverseRange(arr, k, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " \n"[i == n - 1];
    return 0;
}