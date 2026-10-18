#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    sz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);

    int components = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int ra = find(a), rb = find(b);
        if (ra == rb) continue;
        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        components--;
    }
    cout << components << endl;
    return 0;
}