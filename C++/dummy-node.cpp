#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* build(int len) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int i = 0; i < len; i++) {
        int x; cin >> x;
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy.next;
}

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (a && b) {
        if (a->val <= b->val) { tail->next = a; a = a->next; }
        else                  { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;

    return dummy.next;
}

int main() {
    int n, m;
    cin >> n >> m;
    ListNode* l1 = build(n);
    ListNode* l2 = build(m);

    ListNode* head = mergeTwoLists(l1, l2);
    for (ListNode* node = head; node; node = node->next) {
        cout << node->val << (node->next ? " " : "");
    }
    cout << endl;

    while (head) {               // free memory
        ListNode* next = head->next;
        delete head;
        head = next;
    }
    return 0;
}