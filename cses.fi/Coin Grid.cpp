#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge
{
	int b, c, f, id;
	edge(int b = 0, int c = 0, int id = 0) : b(b), c(c), id(id), f(0) {};
};

int N, n, s, t;
vector<vector<edge>> graph;

void addedge(int a, int b, int c = 1)
{
	int id1 = graph[b].size(), id2 = graph[a].size();
	graph[a].emplace_back(b, c, id1);
	graph[b].emplace_back(a, 0, id2);
}

vector<int> d, c;

int DFS(int v, int flow = 1e9)
{	
	if (flow == 0) return 0;
	if (v == t) return flow;

	for (; c[v] < graph[v].size(); ++c[v])
	{
		edge& e = graph[v][c[v]];
		if (d[e.b] != d[v] + 1) continue;
		int res = DFS(e.b, min(e.c - e.f, flow));
		if (!res) continue;
		e.f += res;
		graph[e.b][e.id].f -= res;
		return res;
	}
	return 0;
}

bool BFS()
{
	d.assign(n, -1); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size())
	{
		int v = q.front(); q.pop();
		for (auto&i: graph[v])
			if (i.c - i.f > 0)
				if (d[i.b] == -1)
				{
					d[i.b] = d[v] + 1;
					q.push(i.b);
				}
	}
	return d[t] != -1;
}

int maxflow()
{
	int res = 0;
	while (BFS())
	{
		c.assign(n, 0);
		while (int tres = DFS(s))
			res += tres;
	}

	return res;
}

int main()	
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N; n = N * 2 + 2; s = 0; t = n - 1;
	graph.resize(n);
	for (int i = 1; i <= N; ++i) addedge(s, i);
	for (int i = 1; i <= N; ++i) addedge(N + i, t);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			char h; cin >> h;
			if (h == 'o')
				addedge(i, N + j);
		}
	cout << maxflow() << '\n';
	for (int i = 1; i <= N; ++i)
		if (d[i] == -1)
			cout << "1 " << i << '\n';
	for (int i = 1; i <= N; ++i)
		if (d[N + i] != -1)
			cout << "2 " << i << '\n';

	return 0;
}