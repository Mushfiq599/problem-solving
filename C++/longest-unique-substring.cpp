#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    unordered_map<char, int> lastSeen;
    int maxLen = 0, start = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if (lastSeen.count(ch) && lastSeen[ch] >= start) {
            start = lastSeen[ch] + 1;
        }
        lastSeen[ch] = i;
        maxLen = max(maxLen, i - start + 1);
    }

    cout << maxLen << endl;
    return 0;
}