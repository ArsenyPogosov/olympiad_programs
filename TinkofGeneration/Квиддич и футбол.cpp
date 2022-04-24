#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int INF = 1e9;

int n;

struct node {
    int mx, add;
    node(int x = 0) : mx(x), add(0) {}
};

vector<node> tree;

node merge(node a, node b) {
    return node(max(a.mx, b.mx));
}

void fix(int v) {
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void Add(int v, int val) {
    tree[v].mx += val;
    tree[v].add += val;
}

void push(int v) {
    if (!tree[v].add) return;
    Add(v * 2 + 1, tree[v].add);
    Add(v * 2 + 2, tree[v].add);
    tree[v].add = 0;
}

void Add(int v, int l, int r, int L, int R, int val) {
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        Add(v, val);
        return;
    }

    int m = (l + r) / 2;
    push(v);
    Add(v * 2 + 1, l, m, L, R, val);
    Add(v * 2 + 2, m, r, L, R, val);
    fix(v);
}

void Add(int l, int r, int val) {
    Add(0, 0, n + 1, l, r + 1, val);
}

node Query(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return node(-INF);
    if (L <= l && r <= R) return tree[v];
    push(v);
    int m = (l + r) / 2;
    return merge(Query(v * 2 + 1, l, m, L, R), Query(v * 2 + 2, m, r, L, R));
}

int Query(int l, int r) {
    return Query(0, 0, n + 1, l, r + 1).mx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (auto& i : a[0]) cin >> i;
    for (auto& i : a[1]) cin >> i;

    vector<pair<int, int>> order(n * 2);
    for (int i = 0; i < n; ++i) order[i] = { 0, i };
    for (int i = 0; i < n; ++i) order[n + i] = { 1, i };
    sort(order.begin(), order.end(), [&](pair<int, int> l, pair<int, int> r) {
        return a[l.first][l.second] > a[r.first][r.second];
    });

    tree.resize((n + 1) * 4, node(0));
    int it = 0;
    for (auto& i : order) {
        if (i.first == 0)
            Add(i.second + 1, n, 1);
        if (i.first == 1)
            Add(0, i.second, 1);
        int tit = Query(0, n);
        for (; it < tit; ++it)
            cout << a[i.first][i.second] << ' ';
    }
    cout << '\n';

    return 0;
}
