#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge
{
	int v, c, f, id;
	edge(int v = 0, int c = 0, int f = 0, int id = 0): v(v), c(c), f(f), id(id) { }
};

int n, s, t;
vector<vector<edge>> graph;
vector<char> have;

void addedge(int a, int b, int c, int c2 = 0)
{
	graph[a].emplace_back(b, c, 0, graph[b].size());
	graph[b].emplace_back(a, c2, 0, graph[a].size() - 1);
}

vector<int> cnt;
vector<char> d;

bool bfs()
{
	d.assign(n, -1); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size())
	{
		int v = q.front(); q.pop();

		for (auto&i: graph[v])
			if (have[i.v] && i.c - i.f > 0 && d[i.v] == -1)
			{
				d[i.v] = d[v] + 1;
				q.push(i.v);
			}
	}

	return d[t] != -1;
}

int dfs(int v, int flow)
{
	if (v == t) return flow;
	if (flow == 0) return 0;

	for (; cnt[v] < graph[v].size(); ++cnt[v])
	{
		edge& e = graph[v][cnt[v]];
		if (have[e.v] && d[e.v] == d[v] + 1 && e.c - e.f > 0)
		{
			int res = dfs(e.v, min(flow, e.c - e.f));
			if (res > 0)
			{
				e.f += res;
				graph[e.v][e.id].f -= res;

				return res;
			}
		}
	}

	return 0;
}

int minflow()
{
	int res = 0;
	while (bfs())
	{
		cnt.assign(n, 0);
		while (int add = dfs(s, 1e9)) res += add;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, m; cin >> N >> m;
	n = N + 2; s = N; t = N + 1;
	graph.resize(n);
	have.resize(n, 1);
	int totsum = 0;
	vector<int> ssum(N);
	for (int i = 0; i < N; ++i)
	{
		int h; cin >> h;
		totsum += h; ssum[i] += h;
		addedge(s, i, h);
	}
	for (int i = 0; i < N; ++i)
	{
		int h; cin >> h;
		totsum += h; ssum[i] += h;
		addedge(i, t, h);
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b;
		addedge(a, b, c, c);
	}
	cout << totsum - minflow() << '\n';

	int q; cin >> q;
	while (q--)
	{
		for (auto& i : graph)
			for (auto& j : i)
				j.f = 0;
		int h, x; cin >> h;
		if (h == 1)
		{
			cin >> x;
			have[x - 1] = 1;
			totsum += ssum[x - 1];
			cout << totsum - minflow() << '\n';
		}
		if (h == 2)
		{
			cin >> x;
			have[x - 1] = 0;
			totsum -= ssum[x - 1];
			cout << totsum - minflow() << '\n';
		}
		if (h == 3)
		{
			have = vector<char>(n, 1);
			totsum = accumulate(ssum.begin(), ssum.end(), 0);
		}
		if (h == 4)
		{
			for (int i = 0; i < N / 5; ++i)
			{
				have[i] = 0;
				totsum -= ssum[i];
			}
		}
	}

	return 0;
}