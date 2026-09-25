#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n <= 2) { cout << n << endl; return 0; }
    long long prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    cout << prev1 << endl;
    return 0;
}