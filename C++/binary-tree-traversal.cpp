#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int> &vals, int &idx) {
    if (idx >= (int)vals.size() || vals[idx] == -1) { idx++; return nullptr; }
    Node* node = new Node(vals[idx++]);
    node->left = buildTree(vals, idx);
    node->right = buildTree(vals, idx);
    return node;
}

int main() {
    vector<int> vals;
    int x;
    while (cin >> x) vals.push_back(x);

    int idx = 0;
    Node* root = buildTree(vals, idx);

    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        int size = q.size();
        cout << "[";
        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();
            cout << node->val << (i + 1 < size ? ", " : "");
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}