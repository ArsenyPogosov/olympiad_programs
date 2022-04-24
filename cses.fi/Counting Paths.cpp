#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m = 18;
vector<vector<int>> graph, nxt;

vector<int> d;
void DFS(int v, int p = -1)
{
	if (p == -1)
		d[v] = 0;
	else
		d[v] = d[p] + 1;
	for (auto& i : graph[v])
		if (i != p)
		{
			DFS(i, v);
			nxt[0][i] = v;
		}
}

int kup(int v, int k)
{
	for (int i = m - 1; i >= 0; --i)
		if (k >= (1 << i))
		{
			v = nxt[i][v];
			k -= (1 << i);
		}
	return v;
}

vector<int> start, stop;
void add(int a, int b)
{
	if (d[a] < d[b]) swap(a, b);
	++start[a];
	a = kup(a, d[a] - d[b]);
	if (a == b)
	{
		++stop[b];
		return;
	}
	++start[b];
	for (int i = m - 1; i >= 0; --i)
		if (nxt[i][a] != nxt[i][b])
		{
			a = nxt[i][a];
			b = nxt[i][b];
		}
	++stop[nxt[0][a]];
	++stop[b];
}

vector<int> res;
int DFS2(int v, int p = -1)
{
	res[v] = start[v];
	for (auto& i : graph[v])
		if (i != p)
			res[v] += DFS2(i, v);
	return res[v] - stop[v];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; graph.resize(n); nxt.resize(m, vector<int>(n));
	for (int i = 1; i < n; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	d.resize(n);
	DFS(0);
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
	start.resize(n); stop.resize(n);
	while (q--)
	{
		int a, b; cin >> a >> b;
		add(a - 1, b - 1);
	}
	res.resize(n);
	DFS2(0);
	for (auto& i : res) cout << i << ' ';
	cout << '\n';

	return 0;
}