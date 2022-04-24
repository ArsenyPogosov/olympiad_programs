#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge
{
	long long b, c, f, id;
	edge(): f(0) {};
	edge(long long b, long long c = 0, long long id = -1): b(b), c(c), f(0), id(id) {};
};

long long n, s, t;
vector<vector<edge>> graph;

void addEdge(long long a, long long b, long long c = 0)
{
	graph[a].emplace_back(b, c, graph[b].size());
	graph[b].emplace_back(a, 0, graph[a].size() - 1);
}

long long u;
vector<long long> cnt, d;
long long DFS(long long v, long long flow)
{
	if (!flow) return 0;
	if (v == t) return flow;

	for (; cnt[v] < graph[v].size(); ++cnt[v])
	{
		auto& e = graph[v][cnt[v]];
		if (e.c - e.f >= u && d[v] + 1 == d[e.b])
		{
			long long res = DFS(e.b, min(flow, e.c - e.f));
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
	queue<long long> Q;
	Q.push(s); d[s] = 0;
	while (Q.size())
	{
		long long v = Q.front(); Q.pop();
		for (auto&i: graph[v])
			if (d[i.b] == -1 && i.c - i.f >= u)
			{
				d[i.b] = d[v] + 1;
				Q.push(i.b);
			}
	}
	return d[t] != -1;
}

long long maxflow()
{
	long long res = 0;
	u = 1ll << 62;
	while (u > 0)
	{
		while (BFS())
		{
			cnt.assign(n, 0);
			while (long long nres = DFS(s, 1e18)) 
				res += nres;
		}
		u >>= 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long m; cin >> n >> m; s = 0; t = n - 1;
	graph.resize(n);
	while (m--)
	{
		long long a, b, c; cin >> a >> b >> c;
		addEdge(a - 1, b - 1, c);
	}
	cout << maxflow() << '\n';

	return 0;
}