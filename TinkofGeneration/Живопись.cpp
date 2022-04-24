#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

struct edge {
    int to, rev;
    long long c, f;
    edge(int to = 0, long long c = 0, long long f = 0, int rev = 0) : to(to), c(c), f(f), rev(rev) { }
};

int n, m, s, t;
vector<vector<edge>> graph;

void addEdge(int a, int b, long long c, long long rc = 0) {
    graph[a].emplace_back(b, c, 0, graph[b].size() - 0);
    graph[b].emplace_back(a, rc, 0, graph[a].size() - 1);
    m += 2;
}

vector<int> d, cnt;

bool bfs() {
    d.assign(n, -1); d[s] = 0;
    queue<int> q; q.push(s);
    while (q.size()) {
        int v = q.front(); q.pop();

        for (auto& i : graph[v])
            if (d[i.to] == -1 && i.c - i.f) {
                d[i.to] = d[v] + 1;
                q.push(i.to);
            }
    }

    return d[t] != -1;
}

long long dfs(int v, long long flow = INF) {
    if (v == t) return flow;
    if (!flow) return flow;

    for (; cnt[v] < graph[v].size(); ++cnt[v]) {
        edge& e = graph[v][cnt[v]];
        if (d[v] >= d[e.to]) continue;

        long long res = dfs(e.to, min(flow, e.c - e.f));

        if (res) {
            e.f += res;
            graph[e.to][e.rev].f -= res;

            return res;
        }
    }

    return 0;
}

long long maxflow() {
    long long res = 0;
    while (bfs()) {
        cnt.assign(n, 0);
        while (long long tres = dfs(s)) {
            if (tres == INF) return -1;
            res += tres;
        }
    }

    return res;
}

vector<pair<int, int>> adj(int x, int y, int a, int b) {
    vector<pair<int, int>> res, step{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    for (auto& s : step) {
        int nx = x + s.first, ny = y + s.second;
        if (0 <= nx && nx < a && 0 <= ny && ny < b)
            res.emplace_back(nx, ny);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M, w, b, g; cin >> N >> M >> w >> b >> g;
    n = N * M + 2; graph.resize(n);
    s = n - 2; t = n - 1;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            char h; cin >> h;
            if (h == 'W') addEdge(s, i * M + j, b);
            if (h == 'B') addEdge(i * M + j, t, w);

            for (auto& xy : adj(i, j, N, M))
                addEdge(i * M + j, xy.first * M + xy.second, g);
        }

    cout << maxflow() << '\n';

    return 0;
}
