#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;

vector<int> tin, tour, d, cnt;

int dfs1(int v, int p = -1)
{
	tour.push_back(v);
	tin[v] = tour.size() - 1;
	int tup = d[v] = (p != -1 ? d[p] + 1 : 0);

	for (auto& i : graph[v])
	{
		if (i == p) continue;

		if (d[i] != -1)
			tup = min(tup, d[i]);
		else
		{
			tup = min(tup, dfs1(i, v));
			tour.push_back(v);
		}
	}

	if (tup >= d[v] && p != -1)
		cnt[v] = 1;

	return tup;
}

void dfs2(int v, int p = -1)
{
	cnt[v] += (p != -1 ? cnt[p] : 0);
	for (auto& i : graph[v])
	{
		if (d[i] == d[v] + 1)
			dfs2(i, v);
	}
}


vector<int> mlog;
void buildLog(int l)
{
	mlog.resize(l);
	for (int i = 2; i < l; ++i)
		mlog[i] = mlog[i >> 1] + 1;
}

int dmin(int a, int b)
{
	return (d[a] < d[b] ? a : b);
}

vector<vector<int>> sparse;
void buildSparse()
{
	int n = tour.size();
	int k = mlog[n] + 1;

	sparse.resize(k, vector<int>(n));
	sparse[0] = tour;

	for (int i = 1; i < k; ++i)
		for (int j = 0; j < n; ++j)
			sparse[i][j] = dmin(sparse[i - 1][j], sparse[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

int rangeMin(int l, int r)
{
	int d = mlog[r - l + 1];
	return dmin(sparse[d][l], sparse[d][r - (1 << d) + 1]);
}

int LCA(int a, int b)
{
	if (tin[a] > tin[b]) swap(a, b);
	return rangeMin(tin[a], tin[b]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int f; cin >> f; --f;
	graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	tin.resize(n);
	tour.reserve(m * 2 + 1);
	d.resize(n, -1);
	cnt.resize(n);

	dfs1(f);
	dfs2(f);

	buildLog(tour.size() + 1);
	buildSparse();

	int k; cin >> k;
	while (k--)
	{
		int a, b; cin >> a >> b; --a; --b;
		cout << cnt[LCA(a, b)] << '\n';
	}

	return 0;
}