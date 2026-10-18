#include <stdio.h>
#include <stdlib.h>

int *parent, *sz;

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    parent = malloc(sizeof(int) * n);
    sz = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) { parent[i] = i; sz[i] = 1; }

    int components = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ra = find(a), rb = find(b);
        if (ra == rb) continue;
        if (sz[ra] < sz[rb]) { int t = ra; ra = rb; rb = t; }
        parent[rb] = ra;
        sz[ra] += sz[rb];
        components--;
    }

    printf("%d\n", components);
    free(parent); free(sz);
    return 0;
}