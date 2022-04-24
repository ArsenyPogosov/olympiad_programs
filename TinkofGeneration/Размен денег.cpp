#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 2 * (long long)(1e18);

long long n;
vector<long long> a;

struct node {
    vector<long long> sum;
    vector<long long> el;
};

vector<node> tree;

void build(long long v = 0, long long l = 0, long long r = n) {
    if (l + 1 == r) {
        tree[v] = { {a[l]}, {a[l]} };
        return;
    }
    long long m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    tree[v].el.resize(r - l);
    tree[v].sum.resize(r - l);
    merge(tree[v * 2 + 1].el.begin(), tree[v * 2 + 1].el.end(),
        tree[v * 2 + 2].el.begin(), tree[v * 2 + 2].el.end(), tree[v].el.begin());
    partial_sum(tree[v].el.begin(), tree[v].el.end(), tree[v].sum.begin());
}

pair<long long, long long> Query(long long v, long long l, long long r,
    long long L, long long R, long long val) {
    if (r <= L || R <= l) return { 0, INF };
    if (L <= l && r <= R) {
        long long i = lower_bound(tree[v].el.begin(), tree[v].el.end(), val) - tree[v].el.begin();
        if (i == r - l) return { tree[v].sum[r - l - 1], INF };
        return { (i ? tree[v].sum[i - 1] : 0), tree[v].el[i] };
    }

    long long m = (l + r) / 2;
    auto res1 = Query(v * 2 + 1, l, m, L, R, val);
    auto res2 = Query(v * 2 + 2, m, r, L, R, val);
    res1.first += res2.first;
    res1.second = min(res1.second, res2.second);
    return res1;
}

pair<long long, long long> Query(long long l, long long r, long long val) {
    return Query(0, 0, n, l, r + 1, val);
}

long long res(long long l, long long r) {
    long long sum = 0;
    while (true) {
        auto res = Query(l, r, sum + 2);
        sum = res.first;
        if (res.second >= sum + 2)
            return sum + 1;
        sum += res.second;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long q; cin >> n >> q;
    a.resize(n);
    for (auto& i : a) cin >> i;
    tree.resize(n * 4);
    build();

    while (q--) {
        long long l, r; cin >> l >> r;
        cout << res(l - 1, r - 1) << '\n';
    }

    return 0;
}
