#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> w;
vector<vector<long long>> graph;

vector<long long> par, sz;
void DFS1(long long v, long long p = -1)
{
	par[v] = p;
	sz[v] = 1;
	for (auto&i: graph[v])
		if (i != p)
		{
			DFS1(i, v);
			sz[v] += sz[i];
			if (sz[graph[v][0]] < sz[i]) 
				swap(graph[v][0], i);
		}
}

long long t = 0;
vector<long long> top, tin, path;
void DFS2(long long v, long long p = -1)
{
	if (p == -1 || v != graph[p][0])
		top[v] = v;
	else
		top[v] = top[p];
	path[t] = v;
	tin[v] = t++;
	for (auto& i : graph[v])
		if (i != p)
			DFS2(i, v);
}

vector<long long> tree;

void build(long long v = 0, long long l = 0, long long r = n)
{
	if (l + 1 == r)
	{
		tree[v] = w[path[l]];
		return;
	}
	long long m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void change(long long v, long long l, long long r, long long i, long long val)
{
	if (i < l || r <= i) return;
	if (l + 1 == r)
	{
		tree[v] = val;
		return;
	}
	long long m = (l + r) / 2;
	change(v * 2 + 1, l, m, i, val);
	change(v * 2 + 2, m, r, i, val);
	tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void change(long long i, long long val)
{
	change(0, 0, n, tin[i], val);
}

long long query(long long v, long long l, long long r, long long L, long long R)
{
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return tree[v];
	long long m = (l + r) / 2;
	return query(v * 2 + 1, l, m, L, R) + query(v * 2 + 2, m, r, L, R);
}

long long query(long long u, long long v)
{
	return query(0, 0, n, tin[v], tin[u] + 1);
}

long long sum(long long v)
{
	long long res = 0;
	while (v != -1)
	{
		res += query(v, top[v]);
		v = par[top[v]];
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long q; cin >> n >> q; w.resize(n); graph.resize(n);
	for (auto& i : w) cin >> i;
	for (long long i = 0; i < n - 1; ++i)
	{
		long long a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	par.resize(n); sz.resize(n);
	DFS1(0);
	top.resize(n); tin.resize(n); path.resize(n);
	DFS2(0);
	tree.resize(n * 4);
	build();
	while (q--)
	{
		long long reg; cin >> reg;
		if (reg == 1)
		{
			long long v, x; cin >> v >> x;
			change(v - 1, x);
		}
		if (reg == 2)
		{
			long long v; cin >> v;
			cout << sum(v - 1) << '\n';
		}
	}

	return 0;
}