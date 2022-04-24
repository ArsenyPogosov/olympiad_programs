#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int INF = 1e9;
const int NONE = 1e9;

int n;
vector<int> a;

struct node
{
	int imn, imx, idmn, d, l, r;
	node(int i = NONE)
	{
		imn = imx = idmn = i;
		d = INF; l = r = NONE;
	}
};
vector<node> tree;

node merge(node &l, node &r)
{
	if (l.imn == NONE) return r;
	if (r.imn == NONE) return l;

	node res;

	if (a[l.imn] <= a[r.imn])
		res.imn = l.imn;
	else
		res.imn = r.imn;

	if (a[l.imx] >= a[r.imx])
		res.imx = l.imx;
	else
		res.imx = r.imx;

	if (l.d <= r.d)
	{
		res.d = l.d;
		res.idmn = l.idmn;
	}
	else
	{
		res.d = r.d;
		res.idmn = r.idmn;
	}

	return res;
}

void fix(int v)
{
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void changel(int v, int nl)
{
	if (tree[v].imn == NONE) return;

	if (tree[v].d > a[tree[v].imn] - nl)
	{
		tree[v].d = a[tree[v].imn] - nl;
		tree[v].idmn = tree[v].imn;
	}
	if (tree[v].l < nl || tree[v].l == NONE) tree[v].l = nl;
}

void changer(int v, int nr)
{
	if (tree[v].imn == NONE) return;

	if (tree[v].d > nr - a[tree[v].imx])
	{
		tree[v].d = nr - a[tree[v].imx];
		tree[v].idmn = tree[v].imx;
	}
	if (tree[v].r > nr || tree[v].r == NONE) tree[v].r = nr;
}

void del(int v)
{
	tree[v] = node();
}

void push(int v)
{
	if (tree[v].l != NONE)
	{
		changel(v * 2 + 1, tree[v].l);
		changel(v * 2 + 2, tree[v].l);
		tree[v].l == NONE;
	}
	if (tree[v].r != NONE)
	{
		changer(v * 2 + 1, tree[v].r);
		changer(v * 2 + 2, tree[v].r);
		tree[v].r == NONE;
	}
}

void build(int v = 0, int l = 0, int r = n)
{
	if (r - l == 1)
	{
		tree[v] = node(l);
		return;
	}

	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	fix(v);
}

void del(int v, int l, int r, int i)
{
	if (l == i && r - l == 1)
	{
		del(v);
		return;
	}

	int m = (l + r) / 2;
	push(v);
	if (i < m)
		del(v * 2 + 1, l, m, i);
	else
		del(v * 2 + 2, m, r, i);
	fix(v);
}

void changel(int v, int l, int r, int L, int nl)
{
	if (r <= L) return;
	if (L <= l)
	{
		changel(v, nl);
		return;
	}

	int m = (l + r) / 2;
	push(v);
	changel(v * 2 + 1, l, m, L, nl);
	changel(v * 2 + 2, m, r, L, nl);
	fix(v);
}

void changer(int v, int l, int r, int R, int nr)
{
	if (R <= l) return;
	if (r <= R)
	{
		changer(v, nr);
		return;
	}

	int m = (l + r) / 2;
	push(v);
	changer(v * 2 + 1, l, m, R, nr);
	changer(v * 2 + 2, m, r, R, nr);
	fix(v);
}

int take()
{
	int i = tree[0].idmn, d = tree[0].d;
	del(0, 0, n, i);
	changel(0, 0, n, i, a[i]);
	changer(0, 0, n, i, a[i]);
	return d;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n; a.resize(n); tree.resize(n * 4);
		for (auto& i : a) cin >> i;
		build();

		long long res = 0;
		take();
		for (int i = 1; i < n; ++i) 
			res += take();

		cout << res << '\n';
	}

	return 0;
}