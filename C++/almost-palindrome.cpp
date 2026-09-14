#include <bits/stdc++.h>
using namespace std;

bool isPalindromeRange(const string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool almostPalindrome(const string &s) {
    int left = 0, right = (int)s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return isPalindromeRange(s, left + 1, right) ||
                   isPalindromeRange(s, left, right - 1);
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << (almostPalindrome(s) ? "YES" : "NO") << endl;
    return 0;
}