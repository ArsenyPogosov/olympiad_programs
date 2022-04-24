#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

struct Edge {
	int to, f, c, rev;

	Edge(int to = 0, int f = 0, int c = 0, int rev = 0) : to(to), f(f), c(c), rev(rev) {}
};

int n, m, s, t;
int sz[500];
Edge graph[500][500];

void AddEdge(int from, int to, int c)
{
	graph[from][sz[from]++] = Edge(to, 0, c, sz[to]);
	graph[to][sz[to]++] = Edge(from, 0, 0, sz[from] - 1);
}

int d[500];
int cnt[500];

long long dfs(int v, long long maxflow)
{
	if (v == t)
		return maxflow;

	long long res = 0;
	for (; cnt[v] < sz[v] && res < maxflow; ++cnt[v])
	{
		Edge& curr = graph[v][cnt[v]];
		if (d[curr.to] <= d[v] || curr.c - curr.f == 0)
			continue;

		int flow = dfs(curr.to, min(maxflow - res, (long long)curr.c - curr.f));
		curr.f += flow;
		graph[curr.to][curr.rev].f -= flow;
		res += flow;
	}

	return res;
}

bool bfs()
{
	for (int i = 0; i < n; ++i) d[i] = -1;
	d[s] = 0;
	queue<int> q({s});

	while(q.size())
	{
		int v = q.front(); q.pop();

		for (int i = 0; i < sz[v]; ++i)
			if (graph[v][i].c - graph[v][i].f)
				if (d[graph[v][i].to] == -1)
				{
					d[graph[v][i].to] = d[v] + 1;
					q.push(graph[v][i].to);
				}
	}

	return d[t] != -1;
}

long long maxflow()
{
	long long res = 0;
	while (bfs())
	{
		for (int i = 0; i < n; ++i) cnt[i] = 0;
		res += dfs(s, INF);
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m; s = 0; t = n - 1;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b;
		AddEdge(a, b, c);
	}

	cout << maxflow() << '\n';

	return 0;
}