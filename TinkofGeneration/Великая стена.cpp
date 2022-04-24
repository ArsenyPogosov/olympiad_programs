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
            if (d[i.to] == -1 && i.c - i.f)    {
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
        while (long long tres = dfs(s))    {
            if (tres == INF) return -1;
            res += tres;
        }
    }

    return res;
}

vector<pair<int, int>> adj(int x, int y, int a, int b) {
    vector<pair<int, int>> res, step{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    for (auto& i : step) {
        int nx = x + i.first, ny = y + i.second;
        if (0 <= nx && nx < a && 0 <= ny && ny < b)
            res.emplace_back(nx, ny);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, k, l; cin >> a >> b >> k >> l;
    vector<vector<char>> table(a, vector<char>(b));

    while (k--)    {
        int x, y; cin >> x >> y; --x; --y;
        table[x][y] = 1;
    }
    vector<pair<int, int>> tocheck(l);
    while (l--)    {
        int x, y; cin >> x >> y; --x; --y;
        table[x][y] = 2;
        tocheck[l] = { x, y };
    }

    vector<vector<int>> num(a, vector<int>(b));
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)    {
            if (table[i][j] == 1) continue;

            num[i][j] = n++;
            if (table[i][j] == 2) ++n;
        }
    graph.resize(n);

    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)    {
            if (table[i][j] == 1) continue;

            int from = num[i][j];
            if (table[i][j] == 2) {
                addEdge(from, from + 1, 1);
                ++from;
            }

            for (auto& xy : adj(i, j, a, b)) {
                int x = xy.first, y = xy.second;
                if (table[x][y] == 1) continue;

                addEdge(from, num[x][y], INF);
            }
        }

     {
        int x, y;
        cin >> x >> y; --x; --y;
        s = num[x][y];
        cin >> x >> y; --x; --y;
        t = num[x][y];
    }

     d.assign(n, -1); d[s] = 0;
     queue<int> q; q.push(s);
     while (q.size()) {
         int v = q.front(); q.pop();

         for (auto& i : graph[v])
             if (d[i.to] == -1 && i.c == INF) {
                 d[i.to] = d[v] + 1;
                 q.push(i.to);
             }
     }

     if (d[t] != -1) {
         cout << -1 << '\n';
         return 0;
     }

    int res = maxflow();

    cout << res << '\n';
    if (res == -1)
        return 0;

    for (auto& ij : tocheck) {
        int i = ij.first, j = ij.second;
        if (d[num[i][j]] == -1) continue;
        int to;
        for (auto& e : graph[num[i][j]])
            if (e.c == 1) {
                to = e.to;
                break;
            }

        if (d[to] == -1)
            cout << i + 1 << ' ' << j + 1 << '\n';
    }

    return 0;
}
