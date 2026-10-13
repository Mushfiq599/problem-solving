#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> h(n);
    for (auto &x : h) cin >> x;

    int l = 0, r = n - 1;
    long long best = 0;
    while (l < r) {
        best = max(best, min(h[l], h[r]) * (r - l));
        if (h[l] < h[r]) l++;
        else r--;
    }
    cout << best << endl;
    return 0;
}