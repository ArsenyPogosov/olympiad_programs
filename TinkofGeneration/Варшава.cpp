#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

vector<int> sz;
int DFSsz(int v, int p = -1)
{
	sz[v] = 1;
	for (auto& i : graph[v])
		if (i != p)
		{
			sz[v] += DFSsz(i, v);
			if (sz[graph[v][0]] < sz[i])
				swap(graph[v][0], i);
		}

	return sz[v];
}

int t = 0;
vector<int> tour, tin, up, p, d;
void DFStour(int v, int par = -1)
{
	tour[t] = v; tin[v] = t++; p[v] = par; d[v] = (par == -1 ? 0 : d[par] + 1);
	for (auto& i : graph[v])
		if (i != par)
		{
			up[i] = (i == graph[v][0] ? up[v] : i);
			DFStour(i, v);
		}
}

bool ispar(int a, int b)
{
	return (tin[a] <= tin[b]) && (tin[b] < tin[a] + sz[a]);
}

int moveup(int v, int l)
{
	if (d[v] - l >= d[up[v]])
	{
		return tour[tin[v] - l];
	}

	return moveup(p[up[v]], l - (d[v] - d[up[v]] + 1));
}

int lca(int a, int b)
{
	if (ispar(a, b)) return a;
	if (ispar(b, a)) return b;

	int na = p[up[a]];
	if (na >= 0 && !ispar(na, b))
		return lca(na, b);

	int l = d[a] - d[up[a]];
	for (int i = 20; i >= 0; --i)
	{
		if ((1 << i) > l) continue;
		na = moveup(a, (1 << i));
		if (!ispar(na, b))
		{
			l -= (1 << i);
			a = na;
		}
	}

	return p[a];
}

pair<int, pair<int, int>> shiza(int a, int b)
{
	int c = lca(a, b);
	int l = abs(d[a] - d[c]) + abs(d[c] - d[b]), nl = (l - 1) / 2;
	if (abs(d[a] - d[c]) > nl)
		return { l - nl, { moveup(a, nl), c} };
	return { l - nl, {moveup(b, l - nl), b} };
}

int res, megacnt;

struct node
{
	int sum, toadd, t;
	node(int sum = 0, int t = -1) : sum(sum), toadd(0), t(t) {}
};

vector<node> tree;

void add(int v, int val)
{
	if (tree[v].t < t)
		tree[v] = node(0, t);
	tree[v].sum += val;
	tree[v].toadd += val;
}

void push(int v)
{
	if (tree[v].t < t)
		tree[v] = node(0, t);
	else
	{
		add(v * 2 + 1, tree[v].toadd);
		add(v * 2 + 2, tree[v].toadd);
		tree[v].toadd = 0;
	}
}

void add(int v, int l, int r, int L, int R, int val)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		add(v, val);
		return;
	}

	int m = (l + r) / 2;
	push(v);
	add(v * 2 + 1, l, m, L, R, val);
	add(v * 2 + 2, m, r, L, R, val);
}

int get(int v, int l, int r, int i)
{
	if (r <= i || i + 1 <= l) return 2281337;
	if (i <= l && r <= i + 1)
	{
		return (tree[v].t < t ? 0: tree[v].sum);
	}

	int m = (l + r) / 2;
	push(v);
	int x = get(v * 2 + 1, l, m, i);
	int y = get(v * 2 + 2, m, r, i);
	if (x == 2281337) return y;
	return x;
}

bool needadd(int a, int b, int c)
{
	return (get(0, 0, n, tin[a]) + megacnt == 0);
}

void add(int a, int b, int c)
{
	if (!needadd(a, b, c)) return;
	if (c == b && d[a] < d[b])
	{
		int a2 = moveup(b, d[b] - d[a] - 1);
		res -= n - sz[a2];
		++megacnt;
		add(0, 0, n, tin[a2], tin[a2] + sz[a2], -1);
	}
	else
	{
		res -= sz[a];
		add(0, 0, n, tin[a], tin[a] + sz[a], +1);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int q; cin >> n >> q;
	graph.resize(n);

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	sz.resize(n);
	DFSsz(0);

	t = 0;
	tour.resize(n);
	tin.resize(n);
	up.resize(n);
	p.resize(n);
	d.resize(n);
	DFStour(0);

	tree.resize(n * 4 + 1);

	t = 0;
	while (q--)
	{
		res = n; megacnt = 0; ++t;
		int k; cin >> k; --k;
		int s; cin >> s; --s;
		vector<pair<int, pair<int, int>>> a(k);
		for (auto& i : a)
		{
			int h; cin >> h;
			i = shiza(h - 1, s);
		}
		sort(a.begin(), a.end());
		for (auto& i : a)
			add(i.second.first, s, i.second.second);

		cout << res << '\n';
	}

	return 0;
}