#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int a, d;
	bool needpush;
	node() : a(0), d(0), needpush(false) {};
};

vector<node> tree;

void change(int v, int l, int r, int a, int d)
{
	tree[v].a = a;
	tree[v].d = d;
	tree[v].needpush = true;
}

void push(int v, int l, int r)
{
	if (!tree[v].needpush) return;
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, tree[v].a + tree[v].d * 0, tree[v].d);
	change(v * 2 + 2, m, r, tree[v].a + tree[v].d * (m - l), tree[v].d);
	tree[v].needpush = false;
}

void change(int v, int l, int r, int from, int a, int d)
{
	if (r <= from) return;
	if (from <= l) { change(v, l, r, a + d * (from - l), d); return; }
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, from, tree[v].a, tree[v].d);
	change(v * 2 + 2, m, r, from, tree[v].a, tree[v].d);
}

int get(int v, int l, int r, int i)
{
	if (r - l == 1) return tree[v].a;
	int m = (l + r) / 2;
	if (l <= i && i < m)
		return get(v * 2 + 1, l, m, i);
	return get(v * 2 + 2, m, r, i);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
	tree.resize(n * 4 + 5);
	vector<int> ord(n); iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j) { return b[i] < b[j]; });
	for (auto& i : ord)
	{
		int l = i - 1, r = n;
		while (l + 1 < r)
		{

		}
		if (r != n)
			change(0, 0, n, r, b[i])
	}

	return 0;
}