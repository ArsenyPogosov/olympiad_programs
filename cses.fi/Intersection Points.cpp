#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int X, Y;

struct vert
{
	int *x, *y1, *y2;
	vert(): x(new int), y1(new int), y2(new int) {};
};

struct gor
{
	int *x1, *x2, *y;
	gor(): x1(new int), x2(new int), y(new int) {};
};

vector<int> tree;

void change(int v, int l, int r, int i, int add)
{
	if (i < l || r <= i) return;
	if (l + 1 == r)
	{
		tree[v] += add;
		return;
	}
	int m = (l + r) / 2;
	change(v * 2 + 1, l, m, i, add);
	change(v * 2 + 2, m, r, i, add);
	tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void add(int x)
{
	change(0, 0, Y, x, 1);
}

void del(int x)
{
	change(0, 0, Y, x, -1);
}

int query(int v, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return tree[v];
	int m = (l + r) / 2;
	return query(v * 2 + 1, l, m, L, R) +
	       query(v * 2 + 2, m, r, L, R);
}

int sum(int l, int r)
{
	return query(0, 0, Y, l, r + 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vert> a;
	vector<gor> b;
	vector<pair<int, int*>> x, y;
	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			a.push_back(vert());
			x.push_back({ x1, a[a.size() - 1].x });
			y.push_back({ y1, a[a.size() - 1].y1 });
			y.push_back({ y2, a[a.size() - 1].y2 });
		}
		else
		{
			b.push_back(gor());
			y.push_back({ y1, b[b.size() - 1].y });
			x.push_back({ x1, b[b.size() - 1].x1 });
			x.push_back({ x2, b[b.size() - 1].x2 });
		}
	}
	sort(x.begin(), x.end());
	int prev = -1e7, count = -1;
	for (auto& i : x)
	{
		if (i.first != prev)
		{
			prev = i.first;
			++count;
		}
		*i.second = count;
	}
	X = count + 1;
	sort(y.begin(), y.end());
	prev = -1e7, count = -1;
	for (auto& i : y)
	{
		if (i.first != prev)
		{
			prev = i.first;
			++count;
		}
		*i.second = count;
	}
	Y = count + 1;
	vector<vector<int>> start(X), stop(X);
	for (auto& i : b)
	{
		start[*i.x1].push_back(*i.y);
		stop[*i.x2].push_back(*i.y);
	}
	vector<vector<pair<int, int>>> q(X);
	for (auto& i : a)
		q[*i.x].emplace_back(*i.y1, *i.y2);
	long long res = 0;
	tree.resize(Y * 4 + 1);
	for (int i = 0; i < X; ++i)
	{
		for (auto& j : start[i]) add(j);
		for (auto& j : q[i]) res += sum(j.first, j.second);
		for (auto& j : stop[i]) del(j);
	}
	cout << res << '\n';

	return 0;
}