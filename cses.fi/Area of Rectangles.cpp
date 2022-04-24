#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int X, Y;
vector<int> truex, truey;

struct node
{
	int cov, val;
	node() : cov(0), val(0) {}
};

vector<node> tree;

void fix(int v)
{
	if (!tree[v].cov)
		tree[v].val = tree[v * 2 + 1].val + tree[v * 2 + 2].val;
}

void change(int v, int l, int r, int toadd)
{
	tree[v].cov += toadd;
	if (tree[v].cov)
		tree[v].val = truey[r] - truey[l];
	else
	{
		tree[v].val = 0;
		if (l + 1 < r) 
			fix(v);
	}
}

void change(int v, int l, int r, int L, int R, int toadd)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		change(v, l, r, toadd);
		return;
	}
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, L, R, toadd);
	change(v * 2 + 2, m, r, L, R, toadd);
	fix(v);
}

void Add(int l, int r)
{
	change(0, 0, Y, l, r, 1);
}

void Del(int l, int r)
{
	change(0, 0, Y, l, r, -1);
}

int get()
{
	return tree[0].val;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<int>> rect(n, vector<int>(4));
	vector<pair<int, pair<int, int>>> x, y;
	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		x.emplace_back(x1, pair<int, int>{ i, 0 });
		x.emplace_back(x2, pair<int, int>{ i, 2 });
		y.emplace_back(y1, pair<int, int>{ i, 1 });
		y.emplace_back(y2, pair<int, int>{ i, 3 });
	}
	int pre;
	sort(x.begin(), x.end());
	pre = -1e9; X = 0;
	for (auto& i : x)
	{
		if (pre < i.first)
		{
			pre = i.first;
			truex.push_back(pre);
			++X;
		}
		rect[i.second.first][i.second.second] = X - 1;
	}
	sort(y.begin(), y.end());
	pre = -1e9; Y = 0;
	for (auto& i : y)
	{
		if (pre < i.first)
		{
			pre = i.first;
			truey.push_back(pre);
			++Y;
		}
		rect[i.second.first][i.second.second] = Y - 1;
	}
	vector<vector<pair<int, int>>> add(X), del(X);
	for (auto& i : rect)
	{
		add[i[0]].emplace_back(i[1], i[3]);
		del[i[2]].emplace_back(i[1], i[3]);
	}
	long long res = 0;
	tree.resize(Y * 4);
	for (int i = 0; i < X - 1; ++i)
	{
		for (auto& j : add[i])
			Add(j.first, j.second);
		for (auto& j : del[i])
			Del(j.first, j.second);
		res += get() * 1ll * (truex[i + 1] - truex[i]);
	}
	cout << res << '\n';

	return 0;
}