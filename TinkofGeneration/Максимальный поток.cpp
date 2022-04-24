#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

struct edge {
    long long to, f, c, rev;
    edge(long long to = 0, long long f = 0, long long c = 0, long long rev = 0) : to(to), f(f), c(c), rev(rev) { }
};

long long n, m;
vector<vector<edge>> graph;

vector<long long> d, cnt;

bool bfs() {
    d.assign(n, -1); d[0] = 0;
    queue<long long> q; q.push(0);
    while (q.size()) {
        long long v = q.front(); q.pop();
        for (auto& i : graph[v])
            if (d[i.to] == -1 && i.f - i.c) {
                d[i.to] = d[v] + 1;
                q.push(i.to);
            }
    }

    return d[n - 1] != -1;
}

long long dfs(long long v, long long flow) {
    if (v == n - 1) return flow;
    if (!flow) return flow;

    for (; cnt[v] < graph[v].size(); ++cnt[v]) {
        edge& e = graph[v][cnt[v]];
        if (d[e.to] <= d[v]) continue;
        long long res = dfs(e.to, min(flow, e.f - e.c));
        if (res) {
            e.c += res;
            graph[e.to][e.rev].c -= res;

            return res;
        }
    }

    return 0;
}

long long maxflow() {
    long long res = 0;
    while (bfs()) {
        cnt.assign(n, 0);
        while (long long tres = dfs(0, INF)) res += tres;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n);
    for (long long i = 0; i < m; ++i) {
        long long a, b, f; cin >> a >> b >> f; --a; --b;
        graph[a].emplace_back(b, f, 0, graph[b].size());
        graph[b].emplace_back(a, 0, 0, graph[a].size() - 1);
    }

    cout << maxflow() << '\n';

    return 0;
}
