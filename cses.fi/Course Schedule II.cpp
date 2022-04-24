#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

vector<int> ord;
vector<char> used;
void DFSord(int v)
{
	used[v] = true;
	for (auto& i : graph[v])
		if (!used[i])
			DFSord(i);
	ord.push_back(v);
}

int k = 18;
vector<int> d;
vector<vector<pair<int, int>>> nxt;

pair<int, int> mup(int v, int d)
{
	int mn = v;
	for (int i = k - 1; i >= 0; --i)
		if (d >= (1 << i))
		{
			d -= (1 << i);
			mn = min(mn, nxt[i][v].second);
			v = nxt[i][v].first;
		}
	return { v, mn };
}

int smin(int a, int b)
{
	if (d[a] < d[b]) swap(a, b);
	int A = a, B = b;
	auto h = mup(a, d[a] - d[b]);
	a = h.first;
	int mina = h.second, minb = b;
	if (a == b)	return A;
	for (int i = k - 1; i >= 0; --i)
		if (nxt[i][a].first != nxt[i][b].first)
		{
			mina = min(mina, nxt[i][a].second);
			a = nxt[i][a].first;
			minb = min(minb, nxt[i][b].second);
			b = nxt[i][b].first;
		}
	return (mina < minb ? A : B);
}

void fillnxt(int v)
{
	for (int i = 1; i < k; ++i)
	{
		nxt[i][v].first = nxt[i - 1][nxt[i - 1][v].first].first;
		nxt[i][v].second = min(nxt[i - 1][nxt[i - 1][v].first].second,
			nxt[i - 1][v].second);
	}
}

vector<vector<int>> ngraph;

void build(int v)
{
	int par = 0;
	for (auto& i : rgraph[v])
		par = smin(par, i);
	d[v] = d[par] + 1 - (v == 0);
	if (par != v)
		ngraph[par].push_back(v);
	nxt[0][v] = { par, min(par, v) };
	fillnxt(v);
}

int t = 0;
vector<int> tin, tout, tour;

void DFStour(int v)
{
	tin[v] = t; tour[t++] = v;
	for (auto& i : ngraph[v])
		DFStour(i);
	tout[v] = t;
}

vector<int> tree;

void build(int v, int l, int r)
{
	if (l + 1 == r)
	{
		tree[v] = tour[l];
		return;
	}

	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void change(int v, int l, int r, int i, int nval)
{
	if (i < l || r <= i) return;
	if (l + 1 == r)
	{
		tree[v] = nval;
		return;
	}

	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, i, nval);
	change(v * 2 + 2, m, r, i, nval);
	tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void change(int i, int nval)
{
	change(0, 0, n, i, nval);
}

int query(int v, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return 1e9;
	if (L <= l && r <= R)
		return tree[v];

	int m = (l + r) / 2;
	return min(query(v * 2 + 1, l, m, L, R), query(v * 2 + 2, m, r, L, R));
}

int tmin(int l, int r)
{
	return query(0, 0, n, l, r);
}

vector<int> res;

void take(int v)
{
	res.push_back(v);
	change(tin[v], 1e9);
}

void solve(int v)
{
	while (true)
	{
		int targ = tmin(tin[v] + 1, tout[v]);
		if (targ == 1e9) break;
		solve(targ);
	}
	take(v);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; graph.resize(n + 1); rgraph.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		graph[b].push_back(a);
		rgraph[a].push_back(b);
	}
	m += n;
	for (int i = 1; i <= n; ++i)
	{
		graph[0].push_back(i);
		rgraph[i].push_back(0);
	}
	++n;

	ord.reserve(n); used.resize(n);
	DFSord(0); reverse(ord.begin(), ord.end());

	d.resize(n); nxt.resize(k, vector<pair<int, int>>(n)); ngraph.resize(n);
	for (auto& i : ord) build(i);

	tin.resize(n); tout.resize(n); tour.resize(n);
	DFStour(0);

	tree.resize(n * 4);
	build(0, 0, n);

	res.reserve(n);
	solve(0); res.pop_back();

	for (auto& i : res) cout << i << ' ';
	cout << '\n';

	return 0;
}