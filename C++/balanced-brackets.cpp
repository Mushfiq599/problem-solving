#include <bits/stdc++.h>
using namespace std;

bool isBalanced(const string &s) {
    stack<char> st;
    unordered_map<char, char> pairs = { {')','('}, {']','['}, {'}','{'} };

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty() || st.top() != pairs[ch]) return false;
            st.pop();
        }
        // ignore everything else
    }

    return st.empty();
}

int main() {
    string line, input;
    while (getline(cin, line)) {
        input += line + "\n";
    }
    cout << (isBalanced(input) ? "YES" : "NO") << endl;
    return 0;
}