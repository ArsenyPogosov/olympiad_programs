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

vector<vector<pair<int, int>>> graph;

int k = 17;
vector<vector<pair<int, int>>> up;
vector<int> d;

void dfs(int v, int p = -1)
{
	if (p == -1) p = v;

	d[v] = (p != v ? d[p] + 1 : 0);
	up[0][v] = { p, 0 };
	for (auto& i : graph[v])
		if (i.first != p)
		{
			dfs(i.first, v);
			up[0][i.first].second = i.second;
		}
}

pair<int, int> merge(pair<int, int> u, pair<int, int> v)
{
	return { v.first, max(u.second, v.second) };
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
	dfs(0);

	for (int i = 1; i < k; ++i)
		for (int j = 0; j < n; ++j)
			up[i][j] = binMove(binMove({ j, 0 }, i - 1), i - 1);
}

int path(int u_, int v_)
{
	pair<int, int> u{ u_, 0 }, v{ v_, 0 };
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
	v = binMove(v, 0);

	return merge(u, v).second;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m; cin >> n >> m;

	vector<pair<int, pair<int, int>>> edge(m);
	for (auto& i : edge)
		cin >> i.second.first >> i.second.second >> i.first, --i.second.first, --i.second.second;
	sort(edge.begin(), edge.end());

	initDsu();
	graph.resize(n);
	for (auto&i: edge)
	{
		int a = i.second.first, b = i.second.second, c = i.first;
		if (unite(a, b))
		{
			graph[a].emplace_back(b, c);
			graph[b].emplace_back(a, c);
		}
	}

	buildUp();

	int a, b; cin >> a >> b; --a; --b;
	int res = 1e9 * 2;
	for (auto&i: edge)
	{
		int c;

		c = max(path(a, i.second.first), path(i.second.second, b));
		if (c <= i.first)
			res = min(res, i.first+ c);

		c = max(path(a, i.second.second), path(i.second.first, b));
		if (c <= i.first)
			res = min(res, i.first + c);
	}

	cout << res << "\n";

	return 0;
}