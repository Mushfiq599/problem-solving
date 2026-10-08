#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < (int)temp.size(); k++) arr[left + k] = temp[k];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " \n"[i == n - 1];
    return 0;
}