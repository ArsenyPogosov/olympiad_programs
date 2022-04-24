#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<pair<int, int>>> Q;
vector<int> qres;

vector<int> d, cnt;
void dfs(int v) {
    for (auto& i : Q[v])
        if (d[v] + i.first < n)
            qres[i.second] -= cnt[d[v] + i.first];

    ++cnt[d[v]];
    for (auto& i : graph[v])
        d[i] = d[v] + 1, dfs(i);

    for (auto& i : Q[v])
        if (d[v] + i.first < n)
            qres[i.second] += cnt[d[v] + i.first];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    graph.resize(n);
    for (int i = 1; i < n; ++i)    {
        int h; cin >> h;
        graph[h - 1].push_back(i);
    }

    int q; cin >> q;
    Q.resize(n);
    qres.resize(q);
    for (int i = 0; i < q; ++i) {
        int v, h; cin >> v >> h; --v;
        Q[v].emplace_back(h, i);
    }

    d.resize(n); cnt.resize(n);
    dfs(0);

    for (auto& i : qres)
        cout << i << '\n';

    return 0;
}
