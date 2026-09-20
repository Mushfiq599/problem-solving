#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> arr(n);
    for (auto &s : arr) cin >> s;

    unordered_map<string, vector<string>> groups;
    for (auto &s : arr) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    for (auto &[key, group] : groups) {
        cout << "[";
        for (size_t i = 0; i < group.size(); i++) {
            cout << group[i] << (i + 1 < group.size() ? ", " : "");
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}