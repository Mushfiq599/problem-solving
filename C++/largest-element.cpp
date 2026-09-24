#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int k; cin >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : arr) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) minHeap.pop();
    }

    cout << minHeap.top() << endl;
    return 0;
}