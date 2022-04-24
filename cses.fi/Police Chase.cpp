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
	graph[b].emplace_back(a, c, graph[a].size() - 1);
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
		for (auto&i: graph[v])
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

vector<pair<int, int>> mincut()
{
	maxflow();
	vector<pair<int, int>> res;
	for (int i = 0; i < n; ++i)
		if (d[i] != -1)
			for (auto& j : graph[i])
				if (d[j.b] == -1 && j.c > 0)
					res.emplace_back(i, j.b);
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin >> n >> m;
	graph.resize(n);
	while (m--)
	{
		int a, b; cin >> a >> b;
		addEdge(a - 1, b - 1, 1);
	}
	auto res = mincut();
	cout << res.size() << '\n';
	for (auto& i : res) cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return 0;
}