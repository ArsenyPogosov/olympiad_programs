#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> realval;
vector<vector<pair<int, int>>> open, close;

struct Node
{
	int maxval, maxind, toadd;
	Node(int maxval = 0, int maxind = 0, int toadd = 0) : maxval(maxval), maxind(maxind), toadd(toadd) {}
};

Node merge(const Node& l, const Node& r)
{
	return Node(max(l.maxval, r.maxval), (l.maxval >= r.maxval ? l.maxind : r.maxind), 0);
}

void add(Node& v, int val)
{
	v.maxval += val;
	v.toadd += val;
}

vector<Node> tree;

void fix(int v)
{
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void push(int v)
{
	if (!tree[v].toadd) return;

	add(tree[v * 2 + 1], tree[v].toadd);
	add(tree[v * 2 + 2], tree[v].toadd);
	tree[v].toadd = 0;
}

void build(int v, int l, int r)
{
	if (l + 1 == r)
	{
		tree[v].maxind = l;
		return;
	}

	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	fix(v);
}

Node get(int v, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return Node();
	if (L <= l && r <= R) return tree[v];

	push(v);
	int m = (l + r) / 2;
	return merge(get(v * 2 + 1, l, m, L, R), get(v * 2 + 2, m, r, L, R));
}

void add(int v, int l, int r, int L, int R, int val)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		add(tree[v], val);
		return;
	}

	push(v);
	int m = (l + r) / 2;
	add(v * 2 + 1, l, m, L, R, val);
	add(v * 2 + 2, m, r, L, R, val);
	fix(v);
}

void build()
{
	tree.resize(m * 4);
	build(0, 0, m);
}

pair<int, int> rangemax(int l, int r)
{
	Node segment = get(0, 0, m, l, r + 1);
	return {segment.maxval, segment.maxind};
}

void add(int l, int r, int val)
{
	add(0, 0, m, l, r + 1, val);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	vector<pair<int, int*>> vals;
	vector<vector<int>> orderslist(n, vector<int>(4));
	for (auto& i : orderslist)
		for (auto&j: i)
		{
			cin >> j;
			vals.emplace_back(j, &j);
		}

	sort(vals.begin(), vals.end());
	for (auto& i : vals)
	{
		if (realval.empty() || realval.back() < i.first)
			realval.push_back(i.first);
		*i.second = realval.size() - 1;
	}
	m = realval.size();

	open.resize(m); close.resize(m);
	for (auto& i : orderslist)
	{
		open[i[0]].emplace_back(i[2], i[3]);
		close[i[1]].emplace_back(i[2], i[3]);
	}

	build();
	for (auto& i : orderslist)
		add(i[2], i[3], 1);

	int res = -1, resx = -1, resy = -1, cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		for (auto& j : open[i])
		{
			add(j.first, j.second, -1);
			++cnt;
		}

		pair<int, int> h = rangemax(0, m);
		if (cnt + h.first > res)
		{
			res = cnt + h.first;
			resx = i;
			resy = h.second;
		}

		for (auto& j : close[i])
		{
			add(j.first, j.second, +1);
			--cnt;
		}
	}

	cout << realval[resx] << ' ' << realval[resy] << '\n';


	return 0;
}