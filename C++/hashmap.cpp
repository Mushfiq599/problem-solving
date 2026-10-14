#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;
    long long k; cin >> k;

    unordered_map<long long, int> seen;
    seen[0] = 1;
    long long sum = 0;
    long long count = 0;

    for (long long x : arr) {
        sum += x;
        auto it = seen.find(sum - k);
        if (it != seen.end()) count += it->second;
        seen[sum]++;
    }
    cout << count << endl;
    return 0;
}