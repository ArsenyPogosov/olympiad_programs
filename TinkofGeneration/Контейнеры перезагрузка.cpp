#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	long long x, y, sz;
	node* l, * r;
	node(long long x = 0, long long y = rand() * RAND_MAX + rand(), long long sz = 1) : x(x), y(y), sz(sz), l(nullptr), r(nullptr) {}
};
typedef node* treap;

long long size(treap t)
{
	return t ? t->sz : 0;
}

void fix(treap t)
{
	if (!t) return;
	t->sz = size(t->l) + 1 + size(t->r);
}

void split(treap t, long long k, treap& t1, treap& t2)
{
	if (!t)
	{
		t1 = t2 = nullptr;
		return;
	}

	if (t->x < k)
	{
		split(t->r, k, t->r, t2);
		fix(t);
		t1 = t;
	}
	else
	{
		split(t->l, k, t1, t->l);
		fix(t);
		t2 = t;
	}
}

treap merge(treap t1, treap t2)
{
	if (!t1) return t2;
	if (!t2) return t1;

	if (t1->y < t2->y)
	{
		t1->r = merge(t1->r, t2);
		fix(t1);
		return t1;
	}
	else
	{
		t2->l = merge(t1, t2->l);
		fix(t2);
		return t2;
	}
}

long long add(treap& t, long long x)
{
	treap t1, t2; split(t, x, t1, t2);
	long long res = size(t1);
	t = merge(t1, merge(new node(x), t2));
	return res;
}

long long n;
vector<vector<long long>> graph;

vector<long long> res;

long long mmerge(treap& a, treap& b, bool rev)
{
	long long res = 0;
	if (!rev)
	{
		if (b->l) res += mmerge(a, b->l, rev);

		long long h = add(a, b->x);
		if (rev)
			res += h;
		else
			res += size(a) - h - 1;

		if (b->r) res += mmerge(a, b->r, rev);
		return res;
	}
	if (rev)
	{
		if (b->r) res += mmerge(a, b->r, rev);

		long long h = add(a, b->x);
		if (rev)
			res += h;
		else
			res += size(a) - h - 1;

		if (b->l) res += mmerge(a, b->l, rev);
		return res;
	}
}

treap dfs(long long v)
{
	treap now = new node(v);
	res[v] = 0;

	for (auto& i : graph[v])
	{
		treap nxt = dfs(i);
		res[v] += res[i];

		bool rev = false;
		if (size(nxt) > size(now)) swap(nxt, now), rev = true;
		res[v] += mmerge(now, nxt, rev);
	}

	return now;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	graph.resize(n);
	for (auto& i : graph)
	{
		long long h; cin >> h; i.resize(h);
		for (auto& j : i) cin >> j, --j;
	}

	res.resize(n);

	dfs(0);

	for (auto& i : res)
		cout << i << ' ';
	cout << '\n';

	return 0;
}