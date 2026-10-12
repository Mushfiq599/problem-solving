#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    bool result = (n > 0) && ((n & (n - 1)) == 0);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}