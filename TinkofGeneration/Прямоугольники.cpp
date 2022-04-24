#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node {
    int x, y, cnt, size;
    node *l, *r;
    node(int x = 0) : x(x), y(rand()), cnt(1), size(1), l(nullptr), r(nullptr) {}
};
typedef node * treap;

int size(treap t) {
    if (!t) return 0;
    return t->size;
}

void fix(treap t) {
    if (!t) return;
    t->size = size(t->l) + t->cnt + size(t->r);
}

treap merge(treap l, treap r) {
    if (!l) return r;
    if (!r) return l;

    if (l->y < r->y) {
        l->r = merge(l->r, r);
        fix(l);
        return l;
    } {
        r->l = merge(l, r->l);
        fix(r);
        return r;
    }
}

void split(treap t, int val, treap &t1, treap &t2) {
    if (!t)    {
        t1 = t2 = nullptr;
        return;
    }

    if (t->x <= val) {
        split(t->r, val, t->r, t2);
        t1 = t;
        fix(t1);
        return;
    } {
        split(t->l, val, t1, t->l);
        t2 = t;
        fix(t2);
        return;
    }
}

void add(treap& t, int val) {
    treap t1, t2, t23, t3;
    split(t, val - 1, t1, t23);
    split(t23, val, t2, t3);
    if (!t2) {
        t2 = new node(val);
    } else {
        ++t2->cnt;
        ++t2->size;
    }

    t = merge(t1, merge(t2, t3));
}

void del(treap& t, int val) {
    treap t1, t2, t23, t3;
    split(t, val - 1, t1, t23);
    split(t23, val, t2, t3);
    if (t2)    {
        --t2->cnt;
        --t2->size;
        if (!t2->size) t2 = nullptr;
    }

    t = merge(t1, merge(t2, t3));
}

int res(treap &t, int val) {
    treap t1, t2, t23, t3;
    split(t, val - 1, t1, t23);
    split(t23, val, t2, t3);
    int ans = size(t1) - size(t3);
    t = merge(t1, merge(t2, t3));
    return ans;
}

int n;
vector<int> a;

vector<treap> tree;

void build(int v = 0, int l = 0, int r = n) {
    if (l + 1 == r)    {
        tree[v] = new node(a[l]);
        return;
    }

    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    tree[v] = nullptr;
    for (int i = l; i < r; ++i)
        add(tree[v], a[i]);
}

int Query(int v, int l, int r, int L, int R, int val) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) {
        return res(tree[v], val);
    }
    int m = (l + r) / 2;
    return Query(v * 2 + 1, l, m, L, R, val) + Query(v * 2 + 2, m, r, L, R, val);
}

int Query(int l, int r, int val) {
    return Query(0, 0, n, l, r + 1, val);
}

void Change(int v, int l, int r, int i, int val, int pval) {
    if (r <= i || i < l) return;
    add(tree[v], val);
    del(tree[v], pval);
    if (l + 1 == r) return;
    int m = (l + r) / 2;
    Change(v * 2 + 1, l, m, i, val, pval);
    Change(v * 2 + 2, m, r, i, val, pval);
}

void Change(int i, int val) {
    Change(0, 0, n, i, val, a[i]);
    a[i] = val;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n; a.resize(n);
    for (auto& i : a) cin >> i;
    tree.resize(n * 4);
    build();

    int q; cin >> q;
    while (q--) {
        char h; cin >> h;
        if (h == 'C') {
            int i, v; cin >> i >> v;
            Change(i - 1, v);
        }
        if (h == 'Q') {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            int res = Query(x1 - 1, x2 - 1, (y1 + y2) / 2);
            if (res > 0)
                cout << "1\n";
            if (res < 0)
                cout << "2\n";
            if (res == 0)
                cout << "0\n";
        }
    }

    return 0;
}
