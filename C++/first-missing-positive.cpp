#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) { cout << i + 1 << endl; return 0; }
    }
    cout << n + 1 << endl;
    return 0;
}