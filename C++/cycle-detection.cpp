#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> state; // 0=unvisited,1=visiting,2=done

bool hasCycle(int node) {
    if (state[node] == 1) return true;
    if (state[node] == 2) return false;

    state[node] = 1;
    for (int next : graph[node]) {
        if (hasCycle(next)) return true;
    }
    state[node] = 2;
    return false;
}

int main() {
    int numCourses, numPrereqs;
    cin >> numCourses >> numPrereqs;

    graph.assign(numCourses, {});
    for (int i = 0; i < numPrereqs; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    state.assign(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        if (hasCycle(i)) { cout << "NO" << endl; return 0; }
    }
    cout << "YES" << endl;
    return 0;
}