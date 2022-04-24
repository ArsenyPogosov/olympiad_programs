#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int n;

vector<int> dsu, rnk;

void initDsu()
{
	dsu.resize(n);
	iota(dsu.begin(), dsu.end(), 0);
	rnk.resize(n);
}

int get(int v)
{
	return dsu[v] = (dsu[v] != v ? get(dsu[v]) : v);
}

bool unite(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b) return false;

	if (rnk[a] < rnk[b]) swap(a, b);
	dsu[b] = a;
	rnk[a] += (rnk[a] == rnk[b]);
	return true;
}

vector<vector<int>> graph;

int k = 17;
vector<vector<pair<int, int>>> up;
vector<int> d;

void dfs(int v, int p = -1)
{
	if (p == -1) p = v;

	d[v] = (p != v ? d[p] + 1 : 0);
	up[0][v] = { p, p };
	for (auto& i : graph[v])
		if (i != p)
			dfs(i, v);
}

pair<int, int> merge(pair<int, int> u, pair<int, int> v)
{
	return { v.first, min(u.second, v.second) };
}

pair<int, int> binMove(pair<int, int> v, int i)
{
	return merge(v, up[i][v.first]);
}

pair<int, int> move(pair<int, int> v, int d)
{
	for (int i = k - 1; i >= 0; --i)
		if ((d >> i) & 1)
			v = binMove(v, i);

	return v;
}

void buildUp()
{
	d.resize(n);
	up.resize(k, vector<pair<int, int>>(n));
	dfs(1);

	for (int i = 1; i < k; ++i)
		for (int j = 0; j < n; ++j)
			up[i][j] = binMove(binMove({j, n}, i - 1), i - 1);
}

int path(int u_, int v_)
{
	pair<int, int> u{ u_, u_ }, v{ v_, v_ };
	if (d[u.first] > d[v.first]) swap(u, v);
	v = move(v, d[v.first] - d[u.first]);
	if (u.first == v.first)
		return merge(u, v).second;

	for (int i = k - 1; i >= 0; --i)
		if (binMove(u, i).first != binMove(v, i).first)
		{
			u = binMove(u, i);
			v = binMove(v, i);
		}
	u = binMove(u, 0);

	return merge(u, v).second;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m, q; cin >> n >> m >> q; ++n;

	initDsu();
	graph.resize(n);
	for (int i = m; i >= 1; --i)
		for (int j = i * 2; j < n; j += i)
			if (unite(i, j))
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}

	buildUp();

	while (q--)
	{
		int a, b; cin >> a >> b;

		cout << m - path(a, b) + 1 << '\n';
	}

	return 0;
}