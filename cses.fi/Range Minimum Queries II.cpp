#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a;

vector<int> tree;
void build(int v = 0, int l = 0, int r = n)
{
	if (l + 1 == r)
	{
		tree[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void change(int v, int l, int r, int i, int nv)
{
	if (i < l || r <= i) return;
	if (l + 1 == r)
	{
		tree[v] = nv;
		return;
	}
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, i, nv);
	change(v * 2 + 2, m, r, i, nv);
	tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int query(int v, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return 1e9 + 1;
	if (L <= l && r <= R) return tree[v];
	int m = (l + r) / 2;
	return min(query(v * 2 + 1, l, m, L, R), query(v * 2 + 2, m, r, L, R));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; a.resize(n);
	for (auto& i : a) cin >> i;
	tree.resize(n * 4); build();
	while (q--)
	{
		int a, b, c; cin >> a >> b >> c;
		if (a == 1)
			change(0, 0, n, b - 1, c);
		if (a == 2)
			cout << query(0, 0, n, b - 1, c) << '\n';
	}

	return 0;
}