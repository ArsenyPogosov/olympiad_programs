#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long INF = 1e18;

long long GCD(long long a, long long b) {
    return (b ? GCD(b, a % b) : a);
}

long long n;
vector<long long> a;

vector<long long> lg2;

long long m = 20;
vector<vector<long long>> st;

void build() {
    st.resize(m, vector<long long>(n));
    for (long long i = 0; i < n; ++i)
        st[0][i] = abs(a[i]);
    for (long long i = 1; i < m; ++i)
        for (long long j = 0; j < n; ++j)
            st[i][j] = GCD(st[i - 1][j], st[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

long long GCDlr(long long l, long long r) {
    long long k = lg2[r - l + 1];
    return GCD(st[k][l], st[k][r - (1 << k) + 1]);
}

struct node {
    long long mx, add;
    node(long long mx = 0, long long add = 0) : mx(mx), add(add) {}
};

vector<node> tree;

void Add(long long v, long long add) {
    tree[v].mx += add;
    tree[v].add += add;
}

node merge(node a, node b) {
    a.mx = max(a.mx, b.mx); a.add = 0;
    return a;
}

void push(long long v) {
    Add(v * 2 + 1, tree[v].add);
    Add(v * 2 + 2, tree[v].add);
    tree[v].add = 0;
}

void fix(long long v) {
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

node Query(long long v, long long l, long long r, long long L, long long R) {
    if (r <= L || R <= l) return node(-INF);
    if (L <= l && r <= R) return tree[v];

    long long m = (l + r) / 2;
    push(v);
    return merge(Query(v * 2 + 1, l, m, L, R), Query(v * 2 + 2, m, r, L, R));
}

long long Query(long long l, long long r) {
    return Query(0, 0, n, l, r + 1).mx;
}

void Add(long long v, long long l, long long r, long long L, long long R, long long add) {
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        Add(v, add);
        return;
    }

    long long m = (l + r) / 2;
    push(v);
    Add(v * 2 + 1, l, m, L, R, add);
    Add(v * 2 + 2, m, r, L, R, add);
    fix(v);
}

void Add(long long l, long long r, long long add) {
    Add(0, 0, n, l, r + 1, add);
}

void draww() {
    for (long long i = 0; i < n; ++i)
        cout << Query(i, i) << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i;

    lg2.resize(n + 1);
    for (long long i = 0; (1 << i) <= n; ++i)
        fill(lg2.begin() + (1 << i), lg2.begin() + min(n + 1, (1ll << (i + 1))), i);
    build();
    tree.resize(n * 4 + 10);

    long long res = 0;
    stack<long long> fmx;
    for (long long i = n - 1; i >= 0; --i) {
        Add(i + 1, n - 1, a[i]);
        while (fmx.size() && a[fmx.top()] < a[i]) {
            long long b = fmx.top(), e = n - 1; fmx.pop();
            if (fmx.size()) e = fmx.top() - 1;
            Add(b, e, a[b] - a[i]);
        }
        fmx.push(i);
        long long tek = i, d;
        while (tek < n)    {
            d = GCDlr(i, tek);
            long long l = tek, r = n;
            while (l + 1 < r) {
                long long m = (l + r) / 2;
                if (GCDlr(i, m) == d)
                    l = m;
                else
                    r = m;
            }
            res = max(res, d * Query(tek, r - 1));
            tek = r;
        }
    }
    cout << res << '\n';

    return 0;
}
