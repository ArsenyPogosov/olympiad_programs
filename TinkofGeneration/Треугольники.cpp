#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;

bool gr(int i, int j) {
    return make_pair(graph[i].size(), i) > make_pair(graph[j].size(), j);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; ++i)    {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int t = 0, res = 0;
    vector<int> adj(n);
    for (int i = 0; i < n; ++i)    {
        ++t;
        for (auto& j : graph[i])
            adj[j] = t;

        for (auto& j : graph[i])
            if (gr(i, j))
                for (auto& k : graph[j])
                    if (gr(j, k))
                        if (adj[k] == t)
                            ++res;
    }

    cout << res;

    return 0;
}
