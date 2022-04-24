#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int mx, add;
	node() : mx(0), add(0) {};
};

vector<node> tree;

void change(int v, int add)
{
	tree[v].mx += add; tree[v].add += add;
}

void push(int v)
{
	change(v * 2 + 1, tree[v].add);
	change(v * 2 + 2, tree[v].add);
	tree[v].add = 0;
}

void change(int v, int l, int r, int L, int R, int add)
{
	if (r < L || R < l) return;
	if (L <= l && r <= R) { change(v, add); return; }
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, L, R, add);
	change(v * 2 + 2, m + 1, r, L, R, add);
	tree[v].mx = max(tree[v * 2 + 1].mx, tree[v * 2 + 2].mx);
}

int mx(int v, int l, int r, int L, int R)
{
	if (r < L || R < l) return -1;
	if (L <= l && r <= R) return tree[v].mx;
	int m = (l + r) / 2;
	return max(mx(v * 2 + 1, l, m, L, R),
		mx(v * 2 + 2, m + 1, r, L, R));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		tree.assign(n * 4 + 5, node());
		vector<int> pos(n);
		for (int i = 0; i < n; ++i)
		{
			int h; cin >> h;
			pos[h - 1] = i;
		}
		bool bad = false;
		set<int> ws;
		for (int i = 0; i < n; ++i) ws.insert(i);
		for (int i = 0; i < n; ++i)
		{
			if (mx(0, 0, n - 1, 0, n - 1) != mx(0, 0, n - 1, i, i))
			{
				bad = true; break;
			}
			int b = 0, e = -1;
			auto it = ws.find(i);
			if (it != ws.begin()) b = (*prev(it)) + 1;
			if (it != ws.end() && next(it) != ws.end()) e = (*next(it));
			change(0, 0, n - 1, 1, i - b, -1);
			if (e != 1e9)
			{
				change(0, 0, n - 1, e - i, b - i, 1);
			}
		}
		if (bad)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}