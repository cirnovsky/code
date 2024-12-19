#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int freq;
    int lazy;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct SparseSegtree {
    Node* root;
    int n;
} SparseSegtree;

Node* new_node() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->freq = 0;
    node->lazy = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int comb(int a, int b) {
    return a + b;
}

void apply(Node* cur, int len, int val) {
    if (val == 1) {
        cur->lazy = val;
        cur->freq = len * val;
    }
}

void push_down(Node* cur, int l, int r) {
    if (cur->left == NULL) cur->left = new_node();
    if (cur->right == NULL) cur->right = new_node();
    int m = (l + r) / 2;
    apply(cur->left, m - l + 1, cur->lazy);
    apply(cur->right, r - m, cur->lazy);
    cur->lazy = 0; // Clear lazy after propagation
}

void range_set(Node* cur, int l, int r, int ql, int qr, int val) {
    if (qr < l || ql > r) return;
    if (ql <= l && r <= qr) {
        apply(cur, r - l + 1, val);
    } else {
        push_down(cur, l, r);
        int m = (l + r) / 2;
        range_set(cur->left, l, m, ql, qr, val);
        range_set(cur->right, m + 1, r, ql, qr, val);
        cur->freq = comb(cur->left->freq, cur->right->freq);
    }
}

int range_sum(Node* cur, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return cur->freq;
    push_down(cur, l, r);
    int m = (l + r) / 2;
    return comb(range_sum(cur->left, l, m, ql, qr),
                range_sum(cur->right, m + 1, r, ql, qr));
}

SparseSegtree* create_sparse_segtree(int n) {
    SparseSegtree* st = (SparseSegtree*)malloc(sizeof(SparseSegtree));
    st->root = new_node();
    st->n = n;
    return st;
}

void sparse_segtree_range_set(SparseSegtree* st, int ql, int qr, int val) {
    range_set(st->root, 0, st->n - 1, ql, qr, val);
}

int sparse_segtree_range_sum(SparseSegtree* st, int ql, int qr) {
    return range_sum(st->root, 0, st->n - 1, ql, qr);
}

int main() {
    int query_num;
    scanf("%d", &query_num);

    const int RANGE_SIZE = 1000000000;
    SparseSegtree* st = create_sparse_segtree(RANGE_SIZE + 1);

    int c = 0;
    for (int i = 0; i < query_num; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        if (type == 1) {
            c = sparse_segtree_range_sum(st, x + c, y + c);
            printf("%d\n", c);
        } else if (type == 2) {
            sparse_segtree_range_set(st, x + c, y + c, 1);
        }
    }

    return 0;
}
