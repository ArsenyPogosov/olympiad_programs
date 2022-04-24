#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> Graph, check, f;

bool relax()
{
	queue<int> Q;
	vector<int> p(n, -1);
	Q.push(0);
	while (Q.size())
	{
		int u = Q.front(); Q.pop();
		for (auto& v : check[u])
			if (Graph[u][v] - f[u][v] > 0 && p[v] == -1)
			{
				Q.push(v);
				p[v] = u;
			}
	}
	if (p[n - 1] == -1) return false;

	int d = 1e9, t = n - 1;
	while (t != 0)
	{
		d = min(d, Graph[p[t]][t] - f[p[t]][t]);
		t = p[t];
	}
	t = n - 1;
	while (t != 0)
	{
		f[p[t]][t] += d;
		f[t][p[t]] -= d;
		t = p[t];
	}
	return true;
}

int main()
{
	cin >> n >> m;
	Graph.resize(n, vector<int>(n));
	check.resize(n);
	f.resize(n, vector<int>(n));
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b;
		Graph[a][b] = c;
		check[a].push_back(b);
		check[b].push_back(a);
	}
	while (relax());
	int s = 0;
	for (auto& i : f[0]) s += i;
	cout << s << '\n';

	return 0;
}
