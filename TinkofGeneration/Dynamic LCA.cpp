#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

int t = 0;
vector<int> tin, d, path;

void DFS(int v, int p = -1) {
    path[tin[v] = t++] = v;
    d[v] = (p != -1 ? d[p] + 1 : 0);
    for (auto&i : graph[v])
        if (i != p) {
            DFS(i, v);
            path[t++] = v;
        }
}

int N, m;
vector<int> lg2;
vector<vector<int>> sparse;

void buildLg2() {
    lg2.resize(N + 1);
    for (int i = 0; (1 << i) <= N; ++i)
        for (int j = (1 << i); j < (1 << (i + 1)) && j <= N; ++j)
            lg2[j] = i;
}

int dmin(int a, int b) {
    return (d[a] <= d[b] ? a : b);
}

void buildSparse() {
    m = lg2[N] + 1;
    sparse.assign(m, vector<int>(N));
    sparse[0] = path;
    for (int i = 1; i < m; ++i)
        for (int j = 0; j < N; ++j)
            sparse[i][j] = dmin(sparse[i - 1][j], sparse[i - 1][min(N - 1, j + (1 << (i - 1)) )]);
}

int lca(int a, int b) {
    a = tin[a]; b = tin[b];
    if (a > b) swap(a, b);
    int i = lg2[b - a + 1];
    return dmin(sparse[i][a], sparse[i][b - (1 << i) + 1]);
}

bool isa(int a, int b) {
    return lca(a, b) == a;
}

int dlca(int a, int b, int v) {
    int x = lca(a, b);
    if (!isa(x, v)) return x;

    a = lca(a, v);
    b = lca(b, v);
    if (isa(a, b)) return b;
    return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true) {
        t = 0;
        cin >> n;
        if (!n) break;
        graph.assign(n, {});

        for (int i = 0; i < n - 1; ++i) {
            int a, b; cin >> a >> b; --a; --b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        N = n * 2 - 1;
        tin.resize(n); d.resize(n); path.resize(N);
        DFS(0);

        buildLg2(); buildSparse();

        int v = 0;
        int q; cin >> q;
        while (q--) {
            char h; cin >> h;
            if (h == '?') {
                int a, b; cin >> a >> b;
                cout << dlca(a - 1, b - 1, v) + 1 << '\n';
            }
            if (h == '!') {
                cin >> v;
                --v;
            }
        }
    }

    return 0;
}
