#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e6;

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

vector<int> adj;
void Adj(int c, int k) {
    if (k == 1)    {
        adj = { 1 - c };
        return;
    }

    Adj(c / 3, k - 1);
    int l = adj.size();
    if (c % 3 == 0)    {
        adj.resize(l * 2);
        copy(adj.begin(), adj.begin() + l, adj.begin() + l * 1);
        for (int i = l * 0; i < l * 1; ++i) adj[i] = adj[i] * 3 + 1;
        for (int i = l * 1; i < l * 2; ++i) adj[i] = adj[i] * 3 + 2;
    }
    if (c % 3 == 1)    {
        adj.resize(l * 2);
        copy(adj.begin(), adj.begin() + l, adj.begin() + l * 1);
        for (int i = l * 0; i < l * 1; ++i) adj[i] = adj[i] * 3 + 0;
        for (int i = l * 1; i < l * 2; ++i) adj[i] = adj[i] * 3 + 2;
    }
    if (c % 3 == 2)    {
        adj.resize(l * 3);
        copy(adj.begin(), adj.begin() + l, adj.begin() + l * 1);
        copy(adj.begin(), adj.begin() + l, adj.begin() + l * 2);
        for (int i = l * 0; i < l * 1; ++i) adj[i] = adj[i] * 3 + 0;
        for (int i = l * 1; i < l * 2; ++i) adj[i] = adj[i] * 3 + 1;
        for (int i = l * 2; i < l * 3; ++i) adj[i] = adj[i] * 3 + 2;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, k; cin >> N >> k;
    vector<vector<int>> a(N, vector<int>(k));
    for (auto& i : a)
        for (auto& j : i)
            cin >> j;

    vector<int> code(N);
    for (int i = 0; i < k; ++i)    {
        vector<int> srt(N);
        for (int j = 0; j < N; ++j)
            srt[j] = a[j][i];
        sort(srt.begin(), srt.end());

        int mid = srt[N / 2] * 2 - (srt[N / 2 - 1] < srt[N / 2]);
        for (int j = 0; j < N; ++j)    {
            code[j] = code[j] * 3;
            if (a[j][i] * 2 < mid) code[j] += 0;
            if (a[j][i] * 2 > mid) code[j] += 1;
            if (a[j][i] * 2 == mid) code[j] += 2;
        }
    }
    n = *max_element(code.begin(), code.end()) + 1 + 2;
    graph.resize(n);

    vector<vector<int>> decode(n - 2);
    for (int i = 0; i < N; ++i)
        decode[code[i]].push_back(i);

    for (int i = 0; i < n - 2; ++i)    {
        int h = i;
        for (int j = 0; j < k - 1; ++j) h /= 3;
        if (h == 1)    {
            addEdge(i, n - 1, decode[i].size());
            continue;
        }
        addEdge(n - 2, i, decode[i].size());

        Adj(i, k);
        for (auto& j : adj)
            if (j < n - 2)
                addEdge(i, j, INF);
    }
    s = n - 2; t = n - 1;

    long long res = maxflow();
    if (res < N / 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    for (int i = 0; i < n - 2; ++i) {
        for (auto&e : graph[i])
            while (e.f > 0 && e.to < n - 2)    {
                cout << decode[i].back() + 1 << ' ' << decode[e.to].back() + 1 << '\n';
                decode[i].pop_back();
                decode[e.to].pop_back();
                --e.f;
            }
    }

    return 0;
}
