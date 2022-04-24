#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

long long n;
vector<long long> a;
vector<vector<long long>> graph;

vector<long long> sz;

long long DFSsz(long long v) {
    sz[v] = 1;
    for (auto& i : graph[v])
        sz[v] += DFSsz(i);

    return sz[v];
}

long long t = 0;
vector<long long> tour, tin, top, par;
void DFStour(long long v) {
    tour[t] = v;
    tin[v] = t++;

    for (auto& i : graph[v])
        if (sz[i] > sz[graph[v][0]])
            swap(i, graph[v][0]);

    for (auto& i : graph[v]) {
        top[i] = (i == graph[v][0] ? top[v] : i);
        par[i] = v;
        DFStour(i);
    }
}

struct node {
    long long sum, add;
    node(long long sum = 0, long long add = 0) : sum(sum), add(add) {}
};

vector<node> tree;

node merge(node a, node b) {
    return node(a.sum + b.sum, 0);
}

void fix(long long v) {
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void add(long long v, long long l, long long r, long long val) {
    tree[v].sum += val * (r - l);
    tree[v].add += val;
}

void push(long long v, long long l, long long r) {
    if (!tree[v].add) return;
    long long m = (l + r) / 2;
    add(v * 2 + 1, l, m, tree[v].add);
    add(v * 2 + 2, m, r, tree[v].add);
    tree[v].add = 0;
}

void build(long long v = 0, long long l = 0, long long r = n) {
    if (l + 1 == r) {
        tree[v] = a[tour[l]];
        return;
    }

    long long m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    fix(v);
}

void add(long long v, long long l, long long r, long long L, long long R, long long val) {
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        add(v, l, r, val);
        return;
    }

    push(v, l, r);
    long long m = (l + r) / 2;
    add(v * 2 + 1, l, m, L, R, val);
    add(v * 2 + 2, m, r, L, R, val);
    fix(v);
}

void add(long long l, long long r, long long val) {
    add(0, 0, n, l, r + 1, val);
}

node query(long long v, long long l, long long r, long long L, long long R) {
    if (r <= L || R <= l) return node(0, 0);
    if (L <= l && r <= R)
        return tree[v];

    push(v, l, r);
    long long m = (l + r) / 2;
    return merge(query(v * 2 + 1, l, m, L, R),
                 query(v * 2 + 2, m, r, L, R));
}

long long sum(long long l, long long r) {
    return query(0, 0, n, l, r + 1).sum;
}

void addtree(long long v, long long val) {
    add(tin[v], tin[v] + sz[v] - 1, val);
}

void addpath(long long v, long long val) {
    while (true) {
        add(tin[top[v]], tin[v], val);
        if (par[top[v]] == -1) break;
        v = par[top[v]];
    }
}

void addall(long long v, long long val) {
    addtree(v, val);
    if (par[v] != -1)
        addpath(par[v], val);
}

long long sumtree(long long v) {
    return sum(tin[v], tin[v] + sz[v] - 1);
}

long long sumpath(long long v) {
    long long res = 0;
    while (true) {
        res += sum(tin[top[v]], tin[v]);
        if (par[top[v]] == -1) break;
        v = par[top[v]];
    }

    return res;
}

long long sumall(long long v) {
    long long res = sumtree(v);
    if (par[v] != -1)
        res += sumpath(par[v]);

    return res;
}

void change(long long a, long long b) {
    long long val = sumall(a) % p;
    addall(b, val);
}

long long res(long long a = n - 1) {
    long long res = sumpath(a);
    if (par[a] != -1)
        res -= sumpath(par[a]);
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long q; cin >> n >> q;

    graph.resize(n);
    for (long long i = 1; i < n; ++i) {
        long long h; cin >> h;
        graph[h].push_back(i);
    }

    sz.resize(n);
    DFSsz(0);
    tour.resize(n); tin.resize(n); top.resize(n); par.resize(n, -1);
    DFStour(0);

    a.resize(n);
    for (auto& i : a) cin >> i;

    tree.resize(n * 4);
    build();

    cout << res() << ' ';
    while (q--) {
        long long a, b; cin >> a >> b;
        change(a, b);
        cout << res() << ' ';
    }
    cout << '\n';

    return 0;
}
