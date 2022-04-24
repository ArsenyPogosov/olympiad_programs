#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	long long x, y, size, sum;
	bool rev;
	node* l, * r;

	node(long long x = 0) : x(x), y(rand()* RAND_MAX + rand()), size(1), sum(x), l(nullptr), r(nullptr) {};
};
typedef node* treap;

long long size(treap t)
{
	return (t ? t->size : 0);
}

long long sum(treap t)
{
	return (t ? t->sum : 0);
}

void fix(treap t)
{
	if (!t) return;

	t->size = size(t->l) + 1 + size(t->r);
	t->sum = sum(t->l) + t->x + sum(t->r);
}

void reverse(treap t)
{
	if (!t) return;
	t->rev ^= true;
	swap(t->l, t->r);
}

void push(treap t)
{
	if (!t) return;
	if (t->rev)
	{
		reverse(t->l);
		reverse(t->r);
		t->rev = false;
	}
}

treap merge(treap t1, treap t2)
{
	if (!t1) return t2;
	if (!t2) return t1;

	if (t1->y < t2->y)
	{
		push(t1);
		t1->r = merge(t1->r, t2);
		fix(t1);
		return t1;
	}
	else
	{
		push(t2);
		t2->l = merge(t1, t2->l);
		fix(t2);
		return t2;
	}
}

void split(treap t, long long k, treap& t1, treap& t2)
{
	if (!t) { t1 = t2 = nullptr; return; }

	push(t);
	if (size(t->l) >= k)
	{
		split(t->l, k, t1, t->l);
		fix(t);
		t2 = t;
	}
	else
	{
		split(t->r, k - size(t->l) - 1, t->r, t2);
		fix(t);
		t1 = t;
	}
}

void add(treap& t, long long x)
{
	t = merge(t, new node(x));
}

long long sum(treap& t, long long a, long long b)
{
	treap t1, t2t3, t2, t3;
	split(t, a, t1, t2t3);
	split(t2t3, b - a + 1, t2, t3);
	long long res = sum(t2);
	t = merge(t1, merge(t2, t3));

	return res;
}

void reverse(treap& t, long long a, long long b)
{
	treap t1, t2t3, t2, t3;
	split(t, a, t1, t2t3);
	split(t2t3, b - a + 1, t2, t3);
	reverse(t2);
	t = merge(t1, merge(t2, t3));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	treap t = nullptr;
	long long n, m; cin >> n >> m;
	for (long long i = 0, h; i < n; ++i)
		cin >> h, add(t, h);

	for (long long i = 0; i < m; ++i)
	{
		long long h, a, b; cin >> h >> a >> b;
		if (h == 1)
			reverse(t, a - 1, b - 1);
		if (h == 2)
			cout << sum(t, a - 1, b - 1) << '\n';
	}
	
	return 0;
}