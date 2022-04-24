#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node {
    int x, count, y, size;
    node* l, * r;
    node(int x = 0) : x(x), count(1), y(rand()), size(1), l(nullptr), r(nullptr) {}
};
typedef node* treap;

int size(treap t) {
    if (!t) return 0;
    return t->size;
}

void fix(treap t) {
    if (!t) return;
    t->size = size(t->l) + t->count + size(t->r);
}

treap merge(treap t1, treap t2) {
    if (!t1) return t2;
    if (!t2) return t1;

    if (t1->y < t2->y) {
        t1->r = merge(t1->r, t2);
        fix(t1);
        return t1;
    } {
        t2->l = merge(t1, t2->l);
        fix(t2);
        return t2;
    }
}

void split(treap t, int val, treap& t1, treap& t2) {
    if (!t) {
        t1 = t2 = nullptr;
        return;
    }

    if (t->x < val) {
        split(t->r, val, t->r, t2);
        fix(t);
        t1 = t;
        return;
    } {
        split(t->l, val, t1, t->l);
        fix(t);
        t2 = t;
        return;
    }
}

void Add(treap& t, int val, int y = rand()) {
    if (!t) {
        t = new node(val);
        t->y = y;
        return;
    }
    if (t->y < y) {
        if (t->x < val)
            Add(t->r, val, y);
        if (t->x > val)
            Add(t->l, val, y);
        if (t->x == val) {
            ++t->count;
            ++t->size;
        }
        fix(t);
        return;
    }

    treap t1, t2, t2t3, t3;
    split(t, val, t1, t2t3);
    split(t2t3, val + 1, t2, t3);
    if (!t2) {
        t2 = new node(val);
    } else {
        ++t2->count;
        ++t2->size;
    }
    t2->y = y;
    t = merge(t1, merge(t2, t3));
}

void Del(treap& t, int val, int y = rand()) {
    if (!t) {
        return;
    }
    if (t->y < y) {
        if (t->x < val)
            Del(t->r, val, y);
        if (t->x > val)
            Del(t->l, val, y);
        if (t->x == val) {
            --t->count;
            --t->size;
            if (!t->size)
                t = nullptr;
        }
        fix(t);
        return;
    }
    treap t1, t2, t2t3, t3;
    split(t, val, t1, t2t3);
    split(t2t3, val + 1, t2, t3);
    if (t2) {
        --t2->count;
        --t2->size;
        t2->y = y;
        if (!t2->size)
            t2 = nullptr;
    }
    t = merge(t1, merge(t2, t3));
}

int CountSmaller(treap& t, int val) {
    treap t1, t2;
    split(t, val, t1, t2);
    int res = size(t1);
    t = merge(t1, t2);

    return res;
}

treap Copy(treap t) {
    if (!t) return nullptr;
    treap res = new node();
    *res = *t;
    res->l = Copy(t->l);
    res->r = Copy(t->r);
    return res;
}

treap UltimateMerge(treap t1, treap t2) {
    if (!t1) return t2;
    if (!t2) return t1;

    if (t1->y >= t2->y) swap(t1, t2);

    treap t2t1, t2t2, t2t23, t2t3;
    split(t2, t1->x, t2t1, t2t23);
    split(t2t23, t1->x + 1, t2t2, t2t3);
    if (t2t2) {
        t1->count += t2t2->count;
        t1->size += t2t2->size;
    }
    t1->l = UltimateMerge(t1->l, t2t1);
    t1->r = UltimateMerge(t1->r, t2t3);
    fix(t1);
    return t1;
}

int n;
vector<int> a;

/*
vector<treap> tree;

void Build(int v = 0, int l = 0, int r = n) {
    if (l + 1 == r)    {
        tree[v] = new node(a[l]);
        return;
    }
    int m = (l + r) / 2;
    Build(v * 2 + 1, l, m);
    Build(v * 2 + 2, m, r);
    tree[v] = UltimateMerge(Copy(tree[v * 2 + 1]), Copy(tree[v * 2 + 2]));
}

void Change(int v, int l, int r, int i, int val) {
    if (i + 1 <= l || r <= i) return;
    Del(tree[v], a[i]);
    Add(tree[v], val);
    if (l + 1 == r) return;

    int m = (l + r) / 2;
    Change(v * 2 + 1, l, m, i, val);
    Change(v * 2 + 2, m, r, i, val);
}

void Change(int i, int val) {
    Change(0, 0, n, i, val);
    a[i] = val;
}

int Query(int v, int l, int r, int L, int R, int val) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R)
        return CountSmaller(tree[v], val);
    int m = (l + r) / 2;
    return Query(v * 2 + 1, l, m, L, R, val) + Query(v * 2 + 2, m, r, L, R, val);
}

int Query(int l, int r, int val) {
    return max(0, r - l + 1 - 2 * Query(0, 0, n, l, r + 1, val));
}
*/

int K = 1024 * 2;
vector<treap> block;

void Change(int i, int val) {
    Del(block[i / K], a[i]);
    Add(block[i / K], val);
    a[i] = val;
}

int Query(int l, int r, int val) {
    int res = r - l + 1;
    while (l <= r) {
        if (!(l % K) && (l + K - 1 <= r)) {
            res -= 2 * CountSmaller(block[l / K], val);
            l += K;
        } else {
            res -= 2 * (a[l] < val);
            ++l;
        }
    }

    return max(res, 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // double t = clock();

    // n = 2 * 1e5;
    cin >> n;
    a.resize(n);
    for (auto& i : a) {
        // i = rand() % int(1e9);
        cin >> i;
    }

    /*
    tree.resize(n * 4);
    Build();
    */

    block.resize(n / K + 1);
    for (int i = 0; i * K < n; ++i)
        for (int j = i * K; j < n && j < (i + 1) * K; ++j)
            Add(block[i], a[j]);

    int q;
    // q = 2 * 1e5;
    cin >> q;
    while (q--) {
        int x, y, z;
        // x = rand() % 2 + 1;
        cin >> x >> y >> z;
        if (x == 1) {
            // y = rand() % n + 1;
            // z = rand() % int(1e9);
            Change(y - 1, z);
        }
        if (x == 2) {
            // y = rand() % int(1e9);
            // z = rand() % n + 1;
            int k;
            // k = rand() % n + 1;
            cin >> k;
            int res = Query(z - 1, k - 1, y);
            cout << res << '\n';
        }
    }

    // cout << (clock() - t) / CLOCKS_PER_SEC << '\n';

    return 0;
}
