#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int L = 1823;

int n, m, s, res;
vector<int> version;
vector<vector<int>> graph;
vector<int> heavy;
vector<map<int, int>> heavyadj;

void HeavyAdjUpd(int i, int a, int b) {
    i = heavy[i];
    if (!--heavyadj[i][a])
        heavyadj[i].erase(a);
    ++heavyadj[i][b];
}

void LightUpd(int i, int nv) {
    if (version[i] == nv) return;

    for (auto& j : graph[i]) {
        if (version[j] == version[i])
            ++res;
        if (version[j] == nv)
            --res;

        if (heavy[j] != -1)
            HeavyAdjUpd(j, version[i], nv);
    }

    version[i] = nv;
}

void HeavyUpd(int i, int nv) {
    if (version[i] == nv) return;

    res += heavyadj[heavy[i]][version[i]] - heavyadj[heavy[i]][nv];
    if (!heavyadj[heavy[i]][version[i]])
        heavyadj[heavy[i]].erase(version[i]);
    if (!heavyadj[heavy[i]][nv])
        heavyadj[heavy[i]].erase(nv);

    for (auto& j : graph[i])
        HeavyAdjUpd(j, version[i], nv);

    version[i] = nv;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    version.resize(n);
    for (auto& i : version) cin >> i;

    res = 0;
    graph.resize(n);
    for (int i = 0; i < m; ++i)    {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (version[a] != version[b])
            ++res;
    }

    s = 0;
    heavy.resize(n, -1);
    for (int i = 0; i < n; ++i)
        if (graph[i].size() > L)
            heavy[i] = s++;

    heavyadj.resize(s);
    for (int i = 0; i < n; ++i)
        if (heavy[i] != -1)
            for (auto& j : graph[i])
                ++heavyadj[heavy[i]][version[j]];

    for (int i = 0; i < n; ++i)
        if (heavy[i] != -1)
            graph[i].erase(remove_if(graph[i].begin(), graph[i].end(), [&](int v) { return heavy[v] == -1; }),
                graph[i].end());

    int q; cin >> q;
    while (q--)    {
        int i, nv; cin >> i >> nv; --i;
        if (heavy[i] == -1)
            LightUpd(i, nv);
        else
            HeavyUpd(i, nv);

        cout << res << '\n';
    }

    return 0;
}
