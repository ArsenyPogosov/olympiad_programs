#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a, tree;

int imax(int x, int y)
{
	return (a[x] > a[y] ? x : y);
}

void build(int v = 0, int l = 0, int r = n)
{
	if (l + 1 == r)
	{
		tree[v] = l;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tree[v] = imax(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void change(int v, int l, int r, int i, int add)
{
	if (i < l || r <= i) return;
	if (l + 1 == r) return;
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, i, add);
	change(v * 2 + 2, m, r, i, add);
	tree[v] = imax(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void change(int i, int d)
{
	a[i] -= d;
	change(0, 0, n, i, -d);
}

int firstgood(int v, int l, int r, int val)
{
	if (a[tree[v]] < val) return -1;
	if (l + 1 == r) return l;
	int m = (l + r) / 2;
	int res = firstgood(v * 2 + 1, l, m, val);
	if (res != -1) return res;
	return firstgood(v * 2 + 2, m, r, val);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; a.resize(n); tree.resize(n * 4 + 1);
	for (auto& i : a) cin >> i;
	build();
	while (q--)
	{
		int h; cin >> h;
		int res = firstgood(0, 0, n, h);
		if (res == -1)
		{
			cout << "0 ";
			continue;
		}
		change(res, h);
		cout << res + 1 << ' ';
	}
	cout << '\n';

	return 0;
}