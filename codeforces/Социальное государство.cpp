#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a, tree;

void change1(int v, int l, int r, int ch)
{
	tree[v] = max(tree[v], ch);
	if (l + 1 == r) a[l] = max(a[l], tree[v]), tree[v] = 0;
}

void change1(int ch)
{
	change1(0, 0, n, ch);
}

void push(int v, int l, int r)
{
	int m = (l + r) / 2;
	change1(v * 2 + 1, l, m, tree[v]);
	change1(v * 2 + 2, m, r, tree[v]);
	tree[v] = 0;
}

void change2(int v, int l, int r, int i, int x)
{
	if (r <= i || i < l) return;
	if (l + 1 == r)
	{
		a[i] = x;
		return;
	}
	push(v, l, r);
	int m = (l + r) / 2;
	change2(v * 2 + 1, l, m, i, x);
	change2(v * 2 + 2, m, r, i, x);
}

void change2(int i, int x)
{
	change2(0, 0, n, i, x);
}

void applyall(int v = 0, int l = 0, int r = n)
{
	if (l + 1 == r) return;
	push(v, l, r);
	int m = (l + r) / 2;
	applyall(v * 2 + 1, l, m);
	applyall(v * 2 + 2, m, r);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n); tree.resize(n * 4 + 1);
	for (auto& i : a) cin >> i;
	int q; cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int h; cin >> h;
		if (h == 1)
		{
			int ind, x; cin >> ind >> x;
			change2(ind - 1, x);
		}
		if (h == 2)
		{
			int x; cin >> x;
			change1(x);
		}
	}
	applyall();
	for (auto& i : a) cout << i << ' ';
	cout << '\n';

	return 0;
}