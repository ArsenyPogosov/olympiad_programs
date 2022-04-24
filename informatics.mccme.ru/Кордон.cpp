//Ћол, € тут id не заполнил, а все равно зашло
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge
{
	int b, c, f, id;
	edge() {};
	edge(int b, int c, int f = 0, int id = 0) : b(b), c(c), f(f), id(id) {}
};

int n, s, t;
vector<vector<edge>> graph;

void addEdge(int a, int b, int c = 1)
{
	graph[a].emplace_back(b, c);
	graph[b].emplace_back(a, 0);
}

vector<int> cnt, d;
int DFS(int v, int flow)
{
	if (!flow) return 0;
	if (v == t) return flow;

	for (; cnt[v] < graph[v].size(); ++cnt[v])
	{
		auto& e = graph[v][cnt[v]];
		if (e.c - e.f == 0 || d[v] + 1 != d[e.b]) continue;
		int res = DFS(e.b, min(flow, e.c - e.f));
		if (res > 0)
		{
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
	d[s] = 0; Q.push(s);
	while (Q.size())
	{
		int v = Q.front(); Q.pop();
		for (auto&i: graph[v])
			if (i.c - i.f > 0 && d[i.b] == -1)
			{
				d[i.b] = d[v] + 1;
				Q.push(i.b);
			}
	}
	return d[t] != -1;
}

int maxflow()
{
	int res = 0;
	while (BFS())
	{
		cnt.assign(n, 0);
		while (int tres = DFS(s, 1e9))
			res += tres;
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
	int N; cin >> N; n = N + 1; s = 0; t = n - 1;
	graph.resize(n);
	int h; cin >> h;
	while (h--)
	{
		int x; cin >> x;
		addEdge(x - 1, t, 1e6);
	}
	int t; cin >> t;
	while (t--)
	{
		int a, b; cin >> a >> b;
		addEdge(a - 1, b - 1);
	}

	auto ans = mincut();
	cout << ans.size() << '\n';
	for (auto& i : ans)
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return 0;
}