#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m, k = 18;
vector<vector<int>> graph;

vector<int> used, d, dup;
vector<vector<int>> nxt;

void DFS(int v, int c)
{
	used[v] = c; dup[v] = d[v];
	for (auto& i : graph[v])
	{
		if (used[i] == -1)
		{
			d[i] = d[v] + 1;
			DFS(i, c);
			nxt[0][i] = v;
			dup[v] = min(dup[v], dup[i]);
		}
		else
			dup[v] = min(dup[v], d[i]);
	}
}

int move(int v, int d)
{
	for (int i = k - 1; i >= 0; --i)
		if (d >= (1 << i))
			v = nxt[i][v], d -= (1 << i);
	return v;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> m >> q; graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	used.resize(n, -1);
	d.resize(n); dup.resize(n);
	nxt.resize(k, vector<int>(n));
	int c = 0;
	for (int i = 0; i < n; ++i)
		if (used[i] == -1)
			DFS(i, c++), nxt[0][i] = i;
	for (int i = 1; i < k; ++i)
		for (int j = 0; j < n; ++j)
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
	while (q--)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b; --c;
		if (used[a] != used[b] || a == c || b == c)
		{
			cout << "NO\n";
			continue;
		}
		if (used[c] != used[a])
		{
			cout << "YES\n";
			continue;
		}
		a = move(a, max(d[a] - d[c] - 1, 0));
		b = move(b, max(d[b] - d[c] - 1, 0));
		if (a == b)
		{
			cout << "YES\n";
			continue;
		}
		if (nxt[0][a] == c && dup[a] >= d[c])
		{
			cout << "NO\n";
			continue;
		}
		if (nxt[0][b] == c && dup[b] >= d[c])
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}

	return 0;
}