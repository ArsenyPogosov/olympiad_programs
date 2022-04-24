#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int c[20], xo;
	long long sum;
	node(): sum(0), xo(0)
	{
		for (int i = 0; i < 20; ++i) c[i] = 0;
	}
};

int n;
vector<int> a;
vector<node> tree;

void change(int v, int l, int r, int xo)
{
	tree[v].xo ^= xo;
	for (int i = 0; xo > 0; ++i, xo /= 2)
		if (xo % 2)
			tree[v].c[i] = r - l - tree[v].c[i];
	tree[v].sum = 0;
	for (int i = 0; i < 20; ++i)
		tree[v].sum += (long long)(tree[v].c[i]) * (1 << i);
}

node merge(node a, node b)
{
	node res;
	for (int i = 0; i < 20; ++i) res.c[i] = a.c[i] + b.c[i];
	res.sum = a.sum + b.sum;
	return res;
}

void build(int v = 0, int l = 0, int r = n)
{
	if (l + 1 == r)
	{
		change(v, l, r, a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void push(int v, int l, int r)
{
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, tree[v].xo);
	change(v * 2 + 2, m, r, tree[v].xo);
	tree[v].xo = 0;
}

void change(int v, int l, int r, int L, int R, int xo)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		change(v, l, r, xo);
		return;
	}
	int m = (l + r) / 2;
	push(v, l, r);
	change(v * 2 + 1, l, m, L, R, xo);
	change(v * 2 + 2, m, r, L, R, xo);
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

node sum(int v, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return node();
	if (L <= l && r <= R)
		return tree[v];
	int m = (l + r) / 2;
	push(v, l, r);
	return merge(sum(v * 2 + 1, l, m, L, R), sum(v * 2 + 2, m, r, L, R));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	tree.resize(4 * n + 5);
	for (auto& i : a) cin >> i;
	build();
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int td, l, r; cin >> td >> l >> r; --l;
		if (td == 1)
		{
			cout << sum(0, 0, n, l, r).sum << '\n';
		}
		if (td == 2)
		{
			int xo; cin >> xo;
			change(0, 0, n, l, r, xo);
		}
	}

	return 0;
}