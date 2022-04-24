#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int INF = int(1e9) + 10;

int n;

struct node {
    long long sum;
    int min1, cnt1, min2, cval;
    bool change;
    node(int x = 0) : sum(x), min1(x), cnt1(1), min2(INF), cval(-INF), change(false) {}
};

vector<node> tree;

node merge(node a, node b) {
    node res = node();
    res.sum = a.sum + b.sum;
    set<int> srt{ a.min1, a.min2, b.min1, b.min2, INF};
    res.min1 = *srt.begin();
    res.min2 = *next(srt.begin());
    res.cnt1 = 0;
    if (res.min1 == a.min1)
        res.cnt1 += a.cnt1;
    if (res.min1 == b.min1)
        res.cnt1 += b.cnt1;

    return res;
}

void fix(int v) {
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void build(int v = 0, int l = 0, int r = n) {
    tree[v].cnt1 = r - l;
    if (l + 1 == r) return;
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
}

void MaxEqual(int v, int val) {
    if (tree[v].min1 >= val) return;
    tree[v].sum -= tree[v].min1 * 1ll * tree[v].cnt1;
    tree[v].min1 = val;
    tree[v].sum += tree[v].min1 * 1ll * tree[v].cnt1;
    tree[v].cval = max(tree[v].cval, val);
    tree[v].change = true;
    return;
}

void push(int v) {
    if (!tree[v].change) return;
    MaxEqual(v * 2 + 1, tree[v].cval);
    MaxEqual(v * 2 + 2, tree[v].cval);
    tree[v].cval = -INF;
    tree[v].change = false;
}

void MaxEqual(int v, int l, int r, int L, int R, int val) {
    if (r <= L || R <= l || tree[v].min1 >= val)
        return;
    if (L <= l && r <= R && val < tree[v].min2) {
        MaxEqual(v, val);
        return;
    }

    push(v);
    int m = (l + r) / 2;
    MaxEqual(v * 2 + 1, l, m, L, R, val);
    MaxEqual(v * 2 + 2, m, r, L, R, val);
    fix(v);
}

void MaxEqual(int l, int r, int val) {
    MaxEqual(0, 0, n, l, r + 1, val);
}

long long Query(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return tree[v].sum;

    push(v);
    int m = (l + r) / 2;
    return Query(v * 2 + 1, l, m, L, R) + Query(v * 2 + 2, m, r, L, R);
}

long long Query(int l, int r) {
    return Query(0, 0, n, l, r + 1);
}

long long GCD(long long a, long long b) {
    return (b ? GCD(b, a % b) : a);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        int k; cin >> n >> k;
        if (n == 0 && k == 0) break;
        tree.assign(n * 4, node());
        build();

        while (k--) {
            char h; cin >> h;
            if (h == '^') {
                int l, r, x; cin >> l >> r >> x; --l; --r;
                MaxEqual(l, r, x);
            }
            if (h == '?') {
                int l, r; cin >> l >> r; --l; --r;
                long long res = Query(l, r), len = r - l + 1, d = GCD(res, len);
                res /= d; len /= d;
                if (len == 1)
                    cout << res << '\n';
                else
                    cout << res << '/' << len << '\n';
            }
        }
    }

    return 0;
}

