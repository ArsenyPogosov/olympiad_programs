#include<bits/stdc++.h>
using namespace std;

long long m;

long long f(long long x)
{
	return (x + m - 1) / m;
}

struct node {
	long long y, x, cnt, size;
	node *l, *r;

	node(long long x): x(x), y(rand() * RAND_MAX + rand()), cnt(f(x)), size(1), l(nullptr), r(nullptr) {}
};
typedef node* treap;

long long cnt(treap t)
{
	return (t ? t->cnt : 0);
}

long long size(treap t)
{
	return (t ? t->size : 0);
}

void fix(treap t)
{
	if (!t) return;

	t->cnt = cnt(t->l) + f(t->x) + cnt(t->r);
	t->size = size(t->l) + 1 + size(t->r);
}

void split(treap t, long long k, treap& a, treap& b)
{
	if (!t)
	{
		a = b = nullptr;
		return;
	}

	if (size(t->l) >= k)
	{
		split(t->l, k, a, t->l);
		fix(t);
		b = t;
	}
	else
	{
		split(t->r, k - size(t->l) - 1, t->r, b);
		fix(t);
		a = t;
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
		return(t1);
	}
	else
	{
		t2->l = merge(t1, t2->l);
		fix(t2);
		return(t2);
	}
}

void change(treap& t, long long x, long long y)
{
	treap t1, t2, t3;
	split(t, x, t1, t2);
	split(t2, 1, t2, t3);
	t = merge(t1, merge(new node(y), t3));
}

void split(treap& t, long long x, long long y)
{
	treap t1, t2, t3;
	split(t, x, t1, t2);
	split(t2, 1, t2, t3);
	t = merge(t1, merge(merge(new node(y), new node(t2->x - y)), t3));
}

void merge(treap& t, long long x)
{
	treap t1, t2, t3, t4;
	split(t, x, t1, t2);
	split(t2, 1, t2, t3);
	split(t3, 1, t3, t4);
	t = merge(t1, merge(new node(t2->x + t3->x), t4));
}

long long chapter(treap t, long long x)
{
	if (!t) return 0;

	if (cnt(t->l) > x)
		return chapter(t->l, x);
	if (cnt(t->l) + f(t->x) > x)
		return size(t->l);
	if (cnt(t->l) + f(t->x) <= x)
		return size(t->l) + 1 + chapter(t->r, x - cnt(t->l) - f(t->x));
}

int main()
{
	treap t = nullptr;

	long long n; cin >> n >> m;
	for (long long i = 0; i < n; ++i)
	{
		long long h; cin >> h;
		t = merge(t, new node(h));
	}
	long long q; cin >> q;
	while (q--)
	{
		string s; cin >> s;
		if (s == "size")
		{
			cout << cnt(t) << '\n';
		}
		if (s == "chapter")
		{
			long long x; cin >> x;
			cout << chapter(t, x - 1) + 1 << '\n';
		}
		if (s == "union")
		{
			long long x; cin >> x;
			merge(t, x - 1);
		}
		if (s == "split")
		{
			long long x, y; cin >> x >> y;
			split(t, x - 1, y);
		}
		if (s == "resize")
		{
			long long x, y; cin >> x >> y;
			change(t, x - 1, y);
		}
	}

	return 0;
}