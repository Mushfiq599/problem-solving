#include <stdio.h>
#include <stdlib.h>

int **adj, *adjCount, *state, numCourses;

int hasCycle(int node) {
    if (state[node] == 1) return 1;
    if (state[node] == 2) return 0;

    state[node] = 1;
    for (int i = 0; i < adjCount[node]; i++) {
        if (hasCycle(adj[node][i])) return 1;
    }
    state[node] = 2;
    return 0;
}

int main() {
    int numPrereqs;
    scanf("%d %d", &numCourses, &numPrereqs);

    adj = malloc(sizeof(int*) * numCourses);
    adjCount = calloc(numCourses, sizeof(int));
    int *cap = malloc(sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        cap[i] = 4;
        adj[i] = malloc(sizeof(int) * cap[i]);
    }

    for (int i = 0; i < numPrereqs; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (adjCount[b] == cap[b]) {
            cap[b] *= 2;
            adj[b] = realloc(adj[b], sizeof(int) * cap[b]);
        }
        adj[b][adjCount[b]++] = a;
    }

    state = calloc(numCourses, sizeof(int));
    int possible = 1;
    for (int i = 0; i < numCourses; i++) {
        if (hasCycle(i)) { possible = 0; break; }
    }

    printf("%s\n", possible ? "YES" : "NO");
    return 0;
}