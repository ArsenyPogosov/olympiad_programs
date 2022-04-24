#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int64_t p = 1e9 + 7;

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

int main()
{
	int m; cin >> n >> m;
	map<int, vector<pair<int, int>>> edges;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b;
		edges[c].emplace_back(a, b);
	}

	initDsu();

	int64_t res = 1;
	for (auto& i : edges)
	{
		int cnt = 0;
		set<pair<int, int>> vars;
		set<int> points;
		for (auto& j : i.second)
		{
			int l = get(j.first), r = get(j.second);
			if (l != r)
			{
				vars.emplace(min(l, r), max(l, r));
				points.insert(l); points.insert(r);
				++cnt;
			}
		}
		int mult = cnt - vars.size() + 1;
		if (points.size() == 3 && vars.size() == 3)
			mult = 3;
			
		res = (res * mult) % p;

		for (auto& j : vars)
			unite(j.first, j.second);
	}

	for (int i = 0; i < n; ++i)
		if (get(i) != get(0))
			res = 0;

	cout << res << "\n";

	return 0;
}