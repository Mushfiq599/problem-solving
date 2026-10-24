#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* newNode(int v) {
    Node* node = malloc(sizeof(Node));
    node->val = v;
    node->next = NULL;
    return node;
}

Node* build(int len) {
    Node dummy = {0, NULL};
    Node* cur = &dummy;
    for (int i = 0; i < len; i++) {
        int x;
        scanf("%d", &x);
        cur->next = newNode(x);
        cur = cur->next;
    }
    return dummy.next;
}

Node* mergeTwoLists(Node* a, Node* b) {
    Node dummy = {0, NULL};
    Node* tail = &dummy;

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
    scanf("%d %d", &n, &m);
    Node* l1 = build(n);
    Node* l2 = build(m);

    Node* head = mergeTwoLists(l1, l2);
    for (Node* node = head; node; node = node->next) {
        printf("%d%s", node->val, node->next ? " " : "");
    }
    printf("\n");

    while (head) {               // free memory
        Node* next = head->next;
        free(head);
        head = next;
    }
    return 0;
}