#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;

    int insertPos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) arr[insertPos++] = arr[i];
    }
    while (insertPos < n) arr[insertPos++] = 0;

    for (int i = 0; i < n; i++) cout << arr[i] << " \n"[i == n - 1];
    return 0;
}