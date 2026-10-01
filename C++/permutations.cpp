#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &current, vector<vector<int>> &result) {
    if ((int)current.size() == (int)nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < (int)nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(n, false);
    backtrack(nums, used, current, result);

    for (auto &p : result) {
        cout << "[";
        for (size_t i = 0; i < p.size(); i++) cout << p[i] << (i + 1 < p.size() ? "," : "");
        cout << "] ";
    }
    cout << endl;
    return 0;
}