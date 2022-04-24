#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int K1 = 800;
const int K2 = 400;

int n;
vector<vector<pair<int, int>>> graph;
vector<int> a;

vector<int> tour, tin, tout;

void DFS(int v, int p = -1) {
    tin[v] = tour.size();
    for (auto& i : graph[v])
        if (i.first != p) {
            tour.push_back(i.second);
            DFS(i.first, v);
            tour.push_back(i.second);
        }
    tout[v] = tour.size();
}

int l = 0, r = 0;
vector<int> cnt, condsqrt;
vector<char> cntedj;

void addval(int val) {
    if (val > n - 2) return;
    if (!cnt[val]++)
        --condsqrt[val / K2];
}

void delval(int val) {
    if (val > n - 2) return;
    if (!--cnt[val])
        ++condsqrt[val / K2];
}

void hiedj(int i) {
    if (cntedj[i] ^= 1)
        addval(a[i]);
    else
        delval(a[i]);
}

void MoveTo(int L, int R) {
    unordered_map<int, char> help;
    while (l > L)
        help[tour[--l]] ^= 1;
    while (r < R)
        help[tour[r++]] ^= 1;

    while (l < L)
        help[tour[l++]] ^= 1;
    while (r > R)
        help[tour[--r]] ^= 1;
    for (auto& i : help)
        if (i.second)
            hiedj(i.first);
}

int Res() {
    int i;
    for (i = 0; condsqrt[i] == 0; ++i) {}
    i *= K2;
    for (; cnt[i]; ++i) {}
    return i;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q; cin >> n >> q;
    graph.resize(n);
    a.resize(n - 1);
    for (int i = 0; i < n - 1; ++i)    {
        int u, v; cin >> u >> v >> a[i]; --u; --v;
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
    }

    tour.reserve(2 * n - 2);
    tin.resize(n);
    tout.resize(n);
    DFS(1);

    vector<pair<int, int>> query(q);
    for (auto& i : query) {
        int u, v; cin >> u >> v; --u; --v;
        int tk = min({ abs(tin[u] - tin[v]), abs(tin[u] - tout[v]),
            abs(tout[u] - tin[v]), abs(tout[u] - tout[v]) });
        if (tk == abs(tin[u] - tin[v])) {
            i.first = tin[u];
            i.second = tin[v];
        } else if (tk == abs(tin[u] - tout[v])) {
            i.first = tin[u];
            i.second = tout[v];
        } else if (tk == abs(tout[u] - tin[v])) {
            i.first = tout[u];
            i.second = tin[v];
        } else if (tk == abs(tout[u] - tout[v])) {
            i.first = tout[u];
            i.second = tout[v];
        }
        if (i.first > i.second)
            swap(i.first, i.second);
    }

    vector<int> order(q);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y) {
        return make_pair(query[x].first / K1, query[x].second * ((query[x].first / K1) % 2 ? -1 : 1)) <
            make_pair(query[y].first / K1, query[y].second * ((query[y].first / K1) % 2 ? -1 : 1));
    });

    cntedj.resize(n - 1);
    cnt.resize(n - 1);
    condsqrt.resize(n / K2 + 1, K2);

    vector<int> res(q);
    for (auto& i : order) {
        MoveTo(query[i].first, query[i].second);
        res[i] = Res();
    }

    for (auto& i : res)
        cout << i << '\n';

    return 0;
}
