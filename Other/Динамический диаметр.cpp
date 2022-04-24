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
	for (auto& i : graph[v])
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
			sparse[i][j] = dmin(sparse[i - 1][j], sparse[i - 1][min(N - 1, j + (1 << (i - 1)))]);
}

int lca(int a, int b) {
	a = tin[a]; b = tin[b];
	if (a > b) swap(a, b);
	int i = lg2[b - a + 1];
	return dmin(sparse[i][a], sparse[i][b - (1 << i) + 1]);
}

int dist(int a, int b)
{
	return d[a] + d[b] - d[lca(a, b)] * 2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	graph.assign(n, {});

	for (int i = 1; i < n; ++i) {
		int p; cin >> p; --p;
		graph[i].push_back(p);
		graph[p].push_back(i);
	}

	N = n * 2 - 1;
	tin.resize(n); d.resize(n); path.resize(N);
	DFS(0);

	buildLg2(); buildSparse();

	int u = 0, v = 0;
	for (int i = 1; i < n; ++i)
	{
		if (d[i] > d[u])
		{
			if (dist(i, u) > dist(i, v))
				v = u;
			u = i;
		}
		else if (dist(u, i) > dist(u, v))
			v = i;

		cout << dist(u, v) << ' ';
	}
	cout << '\n';

	return 0;
}
