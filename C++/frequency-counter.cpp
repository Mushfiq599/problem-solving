#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long *arr = new long long[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    unordered_map<long long, int> freq;
    long long bestNum = 0;
    int bestCount = 0;

    for (int i = 0; i < n; ++i) {
        long long num = arr[i];
        int count = ++freq[num];
        if (count > bestCount || (count == bestCount && num < bestNum)) {
            bestCount = count;
            bestNum = num;
        }
    }

    cout << bestNum << endl;
    delete[] arr;
    return 0;
}