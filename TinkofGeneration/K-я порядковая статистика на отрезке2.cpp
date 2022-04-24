#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;

int n;

struct node {
    int count;
    node* l, * r;
    node(int c = 0) : count(c), l(nullptr), r(nullptr) {}
};
typedef node* tree;

int count(tree t) {
    if (!t) return 0;
    return t->count;
}

tree lson(tree t) {
    if (!t) return nullptr;
    return t->l;
}

tree rson(tree t) {
    if (!t) return nullptr;
    return t->r;
}

tree add(tree v, int l, int r, int i) {
    tree res = new node(1);
    if (v) {
        *res = *v;
        ++res->count;
    }
    if (i <= l && r <= i + 1)
        return res;

    int m = (l + r) / 2;
    if (i < m)
        res->l = add(lson(v), l, m, i);
    if (m <= i)
        res->r = add(rson(v), m, r, i);

    return res;
}

tree add(tree v, int i) {
    return add(v, 0, N, i);
}

int descent(tree a, tree b, int l, int r, int k) {
    if (count(b) - count(a) < k) return -1;
    if (l + 1 == r) return l;

    int m = (l + r) / 2;
    int res = descent(lson(a), lson(b), l, m, k);
    if (res == -1)
        res = descent(rson(a), rson(b), m, r, k - (count(lson(b)) - count(lson(a))));
    return res;
}

vector<tree> root;

int query(int l, int r, int k) {
    return descent(root[l], root[r + 1], 0, N, k);
}

int nxt(int a, int l, int m, int p) {
    return (a * 1ll * l + m) % p;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> a(n);
    int l, m; cin >> a[0] >> l >> m;
    for (int i = 1; i < n; ++i) a[i] = nxt(a[i - 1], l, m, (int)(1e9));

    vector<int> ord(n); iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int l, int r) {
        return a[l] < a[r];
    });
    vector<int> tval;
    for (auto& i : ord) {
        if (!tval.size() || tval.back() < a[i])
            tval.push_back(a[i]);
        a[i] = tval.size() - 1;
    }
    N = tval.size();

    root.resize(n + 1);
    root[0] = nullptr;
    for (int i = 1; i <= n; ++i)
        root[i] = add(root[i - 1], a[i - 1]);

    int b; cin >> b;
    long long res = 0;
    while (b--) {
        int g, x, lx, mx, y, ly, my, k, lk, mk;
        cin >> g >> x >> lx >> mx >> y >> ly >> my >> k >> lk >> mk; --x; --y;
        while (g--) {
            res += tval[query(x, y, k)];
            x = nxt(x, lx, mx, n);
            y = nxt(y, ly, my, n);
            if (x > y) swap(x, y);
            k = nxt(k - 1, lk, mk, n) + 1;
        }
    }

    cout << res << '\n';

    return 0;
}
