//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int n, m;
vector<vector<int>> Graph, f, check;
vector<int> it, d;

void edge(int a, int b, int c)
{
	Graph[a][b] = c;
	check[a].push_back(b);
	check[b].push_back(a);
}

bool cedg(int a, int b)
{
	return Graph[a][b] - f[a][b] > 0;
}

int dfs(int t, int f)
{
	for (; it[t] < check[t].size(); ++it[t])
	{
		int to = check[t][it[t]];
		if (d[to] == d[t] + 1 && cedg(t, to))
		{
			int res = dfs(to, min(f, Graph[t][to] - f[t][to]));

		}
	}
}

bool relax()
{
	queue<int> Q; Q.push(0);
	d.assign(n, -2); d[0] = 0;
	while (Q.size())
	{
		int v = Q.front(); Q.pop();
		for (auto&u: check[v])
			if (cedg(v, u) && d[u] == -2)
			{
				d[u] = d[v] + 1;
				Q.push(u);
			}
	}
	if (d[n - 1] == -2) return false;
	it.assign(n);
	return true;
}

int main()
{
	cin >> n >> m;
	Graph.resize(n, vector<int>(n));
	f.resize(n, vector<int>(n));
	check.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		edge(a - 1, b - 1, c);
	}

	while (relax());

	return 0;
}