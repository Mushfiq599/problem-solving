#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long first = LLONG_MIN, second = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        if (num > first) {
            second = first;
            first = num;
        } else if (num < first && num > second) {
            second = num;
        }
    }

    if (second == LLONG_MIN) cout << -1 << endl;
    else cout << second << endl;

    return 0;
}