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
        long long nf = f - res2;
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

int toint(char h) {
    if ('a' <= h && h <= 'z') return h - 'a';
    return h - 'A' + ('z' - 'a' + 1);
}

char tochar(int x) {
    if (x < ('z' - 'a' + 1)) return 'a' + x;
    return 'A' + x - ('z' - 'a' + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, k; cin >> N >> k; n = k * 2 + 2;
    graph.resize(n);

    vector<vector<int>> cnt(k, vector<int>(k));
    string ss; cin >> ss;
    for (int i = 0; i < N; ++i) {
        char h; cin >> h;
        ++cnt[toint(ss[i])][toint(h)];
    }

    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
            AddEdge(i, k + j, 1, -cnt[i][j]);
    s = n - 2; t = n - 1;
    for (int i = 0; i < k; ++i)
        AddEdge(s, i, 1, 0);
    for (int i = 0; i < k; ++i)
        AddEdge(k + i, t, 1, 0);

    cout << -MinCostFlow() << '\n';

    for (int i = 0; i < k; ++i)
        for (auto& e : graph[i])
            if (e.to != s && e.u - e.f == 0) {
                cout << tochar(e.to - k);
                break;
            }
    cout << '\n';

    return 0;
}
