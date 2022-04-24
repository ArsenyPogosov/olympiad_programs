#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int INF = (int)1e9;

int n;
vector<int> a;
vector<vector<int>> graph;

vector<char> used;
vector<int> sz, level, par;
vector<vector<int>> dist;

vector<map<int, int>> cres;

void DFSsz(int v, int p = -1) {
    sz[v] = 1;
    for (auto&i : graph[v])
        if (i != p && !used[i]) {
            DFSsz(i, v);
            sz[v] += sz[i];
        }
}

void DFSinf(int root, int v, int p = -1) {
    dist[level[root]][v] = (p != -1 ? dist[level[root]][p] + 1 : 0);

    auto it = cres[root].try_emplace(a[v], dist[level[root]][v]).first;
    it->second = min(it->second, dist[level[root]][v]);

    for (auto&i : graph[v])
        if (i != p && !used[i])
            DFSinf(root, i, v);
}

int centroid(int v) {
    DFSsz(v);
    int tek = v, pre = -1;
    while (true) {
        bool good = true;
        for (auto&i : graph[tek])
            if (i != pre && !used[i]) {
                if (sz[i] > sz[v] / 2) {
                    good = false;
                    pre = tek;
                    tek = i;
                    break;
                }
            }

        if (good) return tek;
    }
}

void decompize(int v, int p = -1) {
    v = centroid(v);

    par[v] = p;
    level[v] = (p != -1 ? level[p] + 1 : 0);
    if (level[v] >= dist.size()) dist.push_back(vector<int>(n));
    DFSinf(v, v);
    used[v] = true;
    for (auto& i : graph[v])
        if (!used[i])
            decompize(i, v);
}

void decompize() {
    used.resize(n);
    sz.resize(n);
    level.resize(n);
    par.resize(n);
    cres.resize(n);

    decompize(0);
}

int query(int v, int c) {
    int res = INF;
    int root = v;
    while (root != -1) {
        auto it = cres[root].find(c);
        if (it != cres[root].end())
            res = min(res, it->second + dist[level[root]][v]);

        root = par[root];
    }

    return (res != INF ? res : -1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    graph.resize(n);
    for (int i = 1; i < n; ++i) {
        int v; cin >> v;
        graph[i].push_back(v);
        graph[v].push_back(i);
    }
    a.resize(n);
    for (auto& i : a) cin >> i;

    decompize();

    int q; cin >> q;
    while (q--) {
        int v, c;
        cin >> v >> c;
        cout << query(v, c) << '\n';
    }

    return 0;
}
