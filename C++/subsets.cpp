#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &result) {
    result.push_back(current);
    for (int i = start; i < (int)nums.size(); i++) {
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);

    for (auto &subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) cout << subset[i] << (i + 1 < subset.size() ? "," : "");
        cout << "] ";
    }
    cout << endl;
    return 0;
}