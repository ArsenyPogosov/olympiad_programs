#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> w;
vector<vector<int>> graph;

vector<int> d, sz, par, top, tin;
void DFS1(int v, int p = -1)
{
	par[v] = p;
	if (p == -1)
		d[v] = 0;
	else
		d[v] = d[p] + 1;
	sz[v] = 1;
	for (auto&i: graph[v])
		if (i != p)
		{
			DFS1(i, v);
			sz[v] += sz[i];
			if (sz[graph[v][0]] < sz[i]) swap(graph[v][0], i);
		}
}



int t = 0;
vector<int> order;
void DFS2(int v, int p = -1)
{
	order[t] = v;
	tin[v] = t++;
	for (auto& i : graph[v])
		if (i != p)
			DFS2(i, v);
}

vector<int> tree;

void fix(int v)
{
	tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void build(int v = 0, int l = 0, int r = n)
{
	if (l + 1 == r)
	{
		tree[v] = w[order[l]];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	fix(v);
}

void change(int v, int l, int r, int i, int val)
{
	if (i < l || r <= i) return;
	if (l + 1 == r)
	{
		tree[v] = val;
		return;
	}
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, i, val);
	change(v * 2 + 2, m, r, i, val);
	fix(v);
}

void change(int v, int val)
{
	change(0, 0, n, tin[v], val);
}

int query(int v, int l, int r, int L, int R)
{
	if (l <= r || R <= l) return 1e9 + 1;
	if (L <= l && r <= R) return tree[v];
	int m = (l + r) / 2;
	return min(query(v * 2 + 1, l, m, L, R), query(v * 2 + 2, m, r, L, R));
}

int Minheavy(int v, int u)
{
	if (tin[v] < tin[v]) swap(v, u);
	return query(0, 0, n, tin[u], tin[v]);
}

int Min(int v, int u)
{
	int res = 1e9 + 1;
	while (top[v] != top[u])
	{
		if (d[top[v]] < d[top[u]]) swap(v, u);
		res = max(res, Minheavy(v, top[v]));
		v = par[top[v]];
	}
	return min(res, Minheavy(v, u));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; graph.resize(n)

	return 0;
}