#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a;

vector<vector<int>> tree;

void build(int v = 0, int l = 0, int r = n) {
    if (l + 1 == r) {
        tree[v] = { a[l] };
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    tree[v].resize(r - l);
    merge(tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(),
          tree[v * 2 + 2].begin(), tree[v * 2 + 2].end(),
          tree[v].begin());
}

int Query(int v, int l, int r, int L, int R, int A, int B) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R)
        return (upper_bound(tree[v].begin(), tree[v].end(), B) -
                lower_bound(tree[v].begin(), tree[v].end(), A));
    int m = (l + r) / 2;
    return Query(v * 2 + 1, l, m, L, R, A, B) + Query(v * 2 + 2, m, r, L, R, A, B);
}

int Query(int l, int r, int a, int b) {
    return Query(0, 0, n, l, r + 1, a, b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m; cin >> n >> m;
    a.resize(n);
    for (auto& i : a) cin >> i;
    tree.resize(n * 4 + 2);
    build();

    while (m--)    {
        int l, r, a, b; cin >> l >> r >> a >> b;
        cout << Query(l - 1, r - 1, a, b) << '\n';
    }

    return 0;
}
