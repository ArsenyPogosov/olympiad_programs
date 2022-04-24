//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258863/problems
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

struct Node {
	long long x, y, len;
	bool rev;
	Node* l, * r;
	Node() {};
	Node(long long _x)
	{
		x = _x;
		len = 1;
		rev = false;
		y = (rand() << 15) + rand();
		l = r = nullptr;
	}
};

typedef Node* treap;

long long tlen(treap t)
{
	return t ? t->len : 0;
}

void fix(treap t)
{
	if (!t) return;
	t->len = tlen(t->l) + tlen(t->r) + 1;
}

void push(treap t)
{
	if (!t) return;
	if (t->rev)
	{
		swap(t->l, t->r);
		if (t->l) t->l->rev = !t->l->rev;
		if (t->r) t->r->rev = !t->r->rev;
		t->rev = false;
	}
}

pair<treap, treap> split(treap t, long long k)
{
	if (!t) return { nullptr, nullptr };

	pair<treap, treap> res;
	push(t);
	if (tlen(t->l) >= k)
	{
		res = split(t->l, k);
		t->l = res.second;
		res.second = t;
		fix(res.second);
	}
	else
	{
		res = split(t->r, k - tlen(t->l) - 1);
		t->r = res.first;
		res.first = t;
		fix(res.first);
	}
	return res;
}

treap merge(treap tl, treap tr)
{
	if (!tl) return tr;
	if (!tr) return tl;

	if (tl->y <= tr->y)
	{
		push(tl);
		tl->r = merge(tl->r, tr);
		fix(tl);
		return tl;
	}
	else
	{
		push(tr);
		tr->l = merge(tl, tr->l);
		fix(tr);
		return tr;
	}
}

treap insert(treap t, int v, long long x)
{
	auto t1t2 = split(t, x - 1);
	t1t2.first = merge(t1t2.first, new Node(v));
	t = merge(t1t2.first, t1t2.second);
	return t;
}

int erase(treap &t, long long x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, 1);
	t = merge(t1t23.first, t2t3.second);
	return t2t3.first->x;
}

int get(treap& t, long long x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, 1);
	int res = t2t3.first->x;
	t = merge(merge(t1t23.first, t2t3.first), t2t3.second);
	return res;
}

treap move(treap t, int l, int r)
{
	int x = erase(t, r);
	return insert(t, x, l);
}

treap reverse(treap t, int l, int r)
{
	auto t1t23 = split(t, l - 1);
	auto t2t3 = split(t1t23.second, r - l + 1);
	t2t3.first->rev = !t2t3.first->rev;
	return merge(merge(t1t23.first, t2t3.first), t2t3.second);
}

int main()
{
	srand(time(0) + 27682);
	treap t = nullptr;
	long long n, q, m; cin >> n >> q >> m;
	for (long long i = 1; i <= n; ++i) { int h; cin >> h; t = insert(t, h, i); }

	for (int i = 0; i < q; ++i)
	{
		int h, l, r;
		cin >> h >> l >> r;
		if (h == 1) t = move(t, l, r);
		if (h == 2) t = reverse(t, l, r);
	}

	for (int i = 0; i < m; ++i)
	{
		int b; cin >> b;
		cout << get(t, b) << ' ';
	}

	return 0;
}