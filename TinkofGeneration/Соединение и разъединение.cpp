#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;

vector<int> par, rnk;
vector<pair<int*, int>> hist;

int get(int v) {
    while (par[v] != -1)
        v = par[v];
    return v;
}

bool unite(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return false;

    if (rnk[a] < rnk[b]) swap(a, b);

    hist.emplace_back(&par[b], par[b]);
    par[b] = a;
    hist.emplace_back(&rnk[a], rnk[a]);
    rnk[a] += rnk[b];

    return true;
}

void undo(int k) {
    while (k--) {
        *hist.back().first = hist.back().second;
        hist.pop_back();
    }
}

int q;

int tekres;
vector<int> res;
vector<vector<pair<int, int>>> tree;

void addquery(int v, int l, int r, int L, int R, int a, int b) {
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        tree[v].emplace_back(a, b);
        return;
    }

    int m = (l + r) / 2;
    addquery(v * 2 + 1, l, m, L, R, a, b);
    addquery(v * 2 + 2, m, r, L, R, a, b);
}

void addquery(int l, int r, int a, int b) {
    addquery(0, 0, q, l, r, a, b);
}

void tour(int v = 0, int l = 0, int r = q) {
    int wasres = tekres, wassize = hist.size();

    for (auto& i : tree[v])
        tekres -= unite(i.first, i.second);

    if (l + 1 == r) {
        res[l] = tekres;
    } else {
        int m = (l + r) / 2;
        tour(v * 2 + 1, l, m);
        tour(v * 2 + 2, m, r);
    }

    undo(hist.size() - wassize);
    tekres = wasres;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    if (q == 0) return 0;

    int cnt = 0;
    map<pair<int, int>, int> mp;
    vector<vector<int>> toadd;
    tree.resize(q * 4);
    for (int i = 0; i < q; ++i) {
        char h; cin >> h;
        if (h == '+') {
            int a, b; cin >> a >> b; --a; --b;
            if (a > b) swap(a, b);
            mp[{a, b}] = cnt;
        }
        if (h == '-') {
            int a, b; cin >> a >> b; --a; --b;
            if (a > b) swap(a, b);
            toadd.push_back({ mp[{a, b}], cnt, a, b });
            mp.erase({ a, b });
        }
        if (h == '?') {
            ++cnt;
        }
    }
    q = cnt;
    for (auto& i : mp)
        toadd.push_back({ i.second, q, i.first.first, i.first.second });

    tree.resize(q * 4);
    for (auto& i : toadd)
        if (i[0] < q && i[1] <= q)
            addquery(i[0], i[1], i[2], i[3]);

    tekres = n;
    res.resize(q);
    par.assign(n, -1);
    rnk.assign(n, 0);
    tour();

    for (auto& i : res)
        cout << i << '\n';

    return 0;
}
