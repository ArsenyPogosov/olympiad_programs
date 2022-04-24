#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;

vector<char> used;
vector<int> sz, level, par;
vector<vector<int>> d;
vector<deque<pair<int, int>>> dop;

int t = 1;
vector<int> op{ 0 };

void DFSsz(int v, int p = -1)
{
	sz[v] = 1;
	for (auto& i : graph[v])
		if (i.first != p && !used[i.first])
		{
			DFSsz(i.first, v);
			sz[v] += sz[i.first];
		}
}

void DFSd(int v, int lvl, int p = -1)
{
	for (auto& i : graph[v])
		if (i.first != p && !used[i.first])
		{
			d[lvl][i.first] = d[lvl][v] + i.second;
			DFSd(i.first, lvl, v);
		}
}

int centroid(int v)
{
	DFSsz(v);
	int tek = v, pre = -1;
	while (true)
	{
		bool good = true;
		for (auto& i : graph[tek])
			if (i.first != pre && !used[i.first])
				if (sz[i.first] > sz[v] / 2)
				{
					good = false;
					pre = tek;
					tek = i.first;
					break;
				}

		if (good) return tek;
	}
}

void decompize(int v, int p = -1)
{
	v = centroid(v);
	used[v] = true;
	par[v] = p;
	level[v] = (p != -1 ? level[p] + 1 : 0);
	if (level[v] >= d.size()) d.push_back(vector<int>(n));
	DFSd(v, level[v]);
	for (auto& i : graph[v])
		if (i.first != p && !used[i.first])
			decompize(i.first, v);
}

void decompize()
{
	used.resize(n);
	sz.resize(n);
	level.resize(n);
	par.resize(n);

	decompize(0);

	dop.resize(n, { {(int)1e9 + 1, 0} });
}

void change(int v, int root, int k)
{
	int h = k - d[level[root]][v];
	if (h >= 0)
	{
		while (dop[root].front().first <= h)
			dop[root].pop_front();
		dop[root].emplace_front(h, t - 1);
	}
	int u = par[root];
	if (u == -1) return;
	change(v, u, k);
}

void Change(int v, int k, int num)
{
	++t;
	op.push_back(num);
	change(v, v, k);
}

int query(int v, int root)
{
	int res = lower_bound(dop[root].begin(), dop[root].end(), pair<int, int>{ d[level[root]][v], -1 })->second;
	int u = par[root];
	if (u == -1) return res;
	return max(res, query(v, u));
}

int query(int v)
{
	return op[query(v, v)];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	graph.resize(n);

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	decompize();

	int q; cin >> q;
	while (q--)
	{
		int h; cin >> h;
		if (h == 1)
		{
			int v, d, c; cin >> v >> d >> c;
			Change(v - 1, d, c);
		}
		if (h == 2)
		{
			int v; cin >> v;
			cout << query(v - 1) << '\n';
		}
	}

	return 0;
}