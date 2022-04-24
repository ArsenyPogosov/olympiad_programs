#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 9223372036854775807;

struct edge {
    int to, rev;
    long long u, c, f;
    edge(int to = 0, long long u = 0, long long c = 0, long long f = 0, long long rev = 0) : to(to), u(u), c(c), f(f), rev(rev) { }
};

int n, m, s, t;
vector<vector<edge>> graph;

void AddEdge(int a, int b, long long u, long long c) {
    graph[a].emplace_back(b, u, +c, 0, graph[b].size() - 0);
    graph[b].emplace_back(a, 0, -c, 0, graph[a].size() - 1);
}

vector<long long> d;
vector<int> ep;

void FordFulkerson() {
    vector<long long> nd(n, INF); nd[s] = 0;
    ep.assign(n, -1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (nd[j] < INF) {
                for (auto& e : graph[j]) {
                    if (e.u - e.f > 0) {
                        if (nd[e.to] > nd[j] + e.c + d[j] - d[e.to]) {
                            nd[e.to] = nd[j] + e.c + d[j] - d[e.to];
                            ep[e.to] = e.rev;
                        }
                    }
                }
            }

    for (int i = 0; i < n; ++i)
        d[i] = (nd[i] < INF ? nd[i] - d[i] : INF);
}

void Dijkstra() {
    vector<long long> nd(n, INF); nd[s] = 0;
    ep.assign(n, -1);

    set<pair<long long, int>> dsort;
    for (int i = 0; i < n; ++i)
        dsort.emplace(nd[i], i);

    while (dsort.size()) {
        int v = dsort.begin()->second; dsort.erase(dsort.begin());
        if (nd[v] == INF) break;

        for (auto& e : graph[v]) {
            if (e.u - e.f > 0) {
                if (nd[e.to] > nd[v] + e.c + d[v] - d[e.to]) {
                    dsort.erase({ nd[e.to], e.to });
                    nd[e.to] = nd[v] + e.c + d[v] - d[e.to];
                    dsort.insert({ nd[e.to], e.to });
                    ep[e.to] = e.rev;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
        d[i] = (nd[i] < INF ? nd[i] - d[i] : INF);
}

long long MinCostFlow(long long f = INF) {
    long long res = 0, res2 = 0;
    d.assign(n, 0);

    FordFulkerson();
    while (d[t] < INF) {
        long long nf = f - res;
        int tek;
        tek = t;
        while (ep[tek] != -1) {
            edge e = graph[tek][ep[tek]];
            nf = min(nf, graph[e.to][e.rev].u - graph[e.to][e.rev].f);
            tek = e.to;
        }
        res2 += nf;
        tek = t;
        while (ep[tek] != -1) {
            edge& e = graph[tek][ep[tek]];
            e.f -= nf;
            graph[e.to][e.rev].f += nf;
            res += graph[e.to][e.rev].c * nf;
            tek = e.to;
        }

        Dijkstra();
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, u, c; cin >> a >> b >> u >> c; --a; --b;
        AddEdge(a, b, u, c);
    }
    m <<= 1;
    s = 0; t = n - 1;

    cout << MinCostFlow() << '\n';

    return 0;
}
