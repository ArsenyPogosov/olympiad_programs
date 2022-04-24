#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge
{
	int b, c, f, id;
	edge() : f(0) {};
	edge(int b, int c, int id) : b(b), c(c), f(0), id(id) {};
};

int n;
vector<vector<edge>> graph;

void addEdge(int a, int b, int c)
{
	graph[a].emplace_back(b, c, graph[b].size());
	graph[b].emplace_back(a, 0, graph[a].size() - 1);
}

int u;
vector<int> cnt, d;
int DFS(int v, int flow = 1e9)
{
	if (!flow) return 0;
	if (v == n - 1) return flow;

	for (; cnt[v] < graph[v].size(); ++cnt[v])
	{
		auto& e = graph[v][cnt[v]];
		if (e.c - e.f >= u && d[v] + 1 == d[e.b])
		{
			int res = DFS(e.b, min(flow, e.c - e.f));
			if (!res) continue;
			e.f += res;
			graph[e.b][e.id].f -= res;
			return res;
		}
	}
	return 0;
}

bool BFS()
{
	d.assign(n, -1);
	queue<int> Q;
	Q.push(0); d[0] = 0;
	while (Q.size())
	{
		int v = Q.front(); Q.pop();
		for (auto& i : graph[v])
			if (i.c - i.f >= u && d[i.b] == -1)
			{
				d[i.b] = d[v] + 1;
				Q.push(i.b);
			}
	}
	return d[n - 1] != -1;
}

int maxflow()
{
	int res = 0;
	u = 1 << 30;
	while (u > 0)
	{
		while (BFS())
		{
			cnt.assign(n, 0);
			while (int nres = DFS(0))
				res += nres;
		}
		u >>= 1;
	}
	return res;
}

vector<pair<int, int>> matching()
{
	maxflow();
	vector<pair<int, int>> res;
	for (int i = 1; i < n - 1; ++i)
		for (auto& j : graph[i])
			if (j.c > 0 && j.c - j.f == 0 && j.b < n - 1)
				res.emplace_back(i, j.b);
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M, k; cin >> N >> M >> k; n = 1 + N + M + 1;
	graph.resize(n);
	for (int i = 0; i < N; ++i)
		addEdge(0, 1 + i, 1);
	for (int i = 0; i < M; ++i)
		addEdge(1 + N + i, n - 1, 1);
	while (k--)
	{
		int a, b; cin >> a >> b;
		addEdge(1 + a - 1, 1 + N + b - 1, 1);
	}
	auto res = matching();
	cout << res.size() << '\n';
	for (auto& i : res) cout << i.first - 1 + 1 << ' ' << i.second - N - 1 + 1 << '\n';

	return 0;
}