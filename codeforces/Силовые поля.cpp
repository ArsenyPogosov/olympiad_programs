//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("power.in");
ofstream fout("power.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

struct node
{
	long long x, y, size;
	node *l, *r;
	node()
	{
		x = 0; y = rand(); l = r = nullptr; size = 1;
	}
	node(long long _x)
	{
		x = _x; y = rand(); l = r = nullptr; size = 1;
	}
};
typedef node* tree;

long long size(tree t)
{
	return (t ? t->size : 0);
}

void fix(tree t)
{
	if (!t) return;
	t->size = size(t->l) + 1 + size(t->r);
}

tree merge(tree a, tree b)
{
	if (!a) return b;
	if (!b) return a;
	if (a->y > b->y)
	{
		a->r = merge(a->r, b);
		fix(a);
		return a;
	}
	else
	{
		b->l = merge(a, b->l);
		fix(b);
		return b;
	}
}

pair<tree, tree> splitX(tree t, long long x)
{
	if (!t) return { nullptr, nullptr };
	if (t->x > x)
	{
		auto res = splitX(t->l, x);
		t->l = res.second;
		fix(t);
		res.second = t;
		return res;
	}
	else
	{
		auto res = splitX(t->r, x);
		t->r = res.first;
		fix(t);
		res.first = t;
		return res;
	}
}

pair<tree, tree> splitK(tree t, long long k)
{
	if (!t) return { nullptr, nullptr };
	if (size(t->l) >= k)
	{
		auto res = splitK(t->l, k);
		t->l = res.second;
		fix(t);
		res.second = t;
		return res;
	}
	else
	{
		auto res = splitK(t->r, k - size(t->l) - 1);
		t->r = res.first;
		fix(t);
		res.first = t;
		return res;
	}
}

long long kmax(tree &t, long long k)
{
	auto t1t23 = splitK(t, size(t) - k);
	auto t2t3 = splitK(t1t23.second, 1);
	long long res = t2t3.first->x;
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
	return res;
}

void add(tree& t, long long x)
{
	auto t1t2 = splitX(t, x);
	t1t2.first = merge(t1t2.first, new node(x));
	t = merge(t1t2.first, t1t2.second);
}

void del(tree& t, long long x)
{
	auto t1t23 = splitX(t, x - 1);
	t1t23.second = splitK(t1t23.second, 1).second;
	t = merge(t1t23.first, t1t23.second);
}

struct point
{
	long long x, y;
	point() : x(0), y(0) {};
	point(long long x, long long y) : x(x), y(y) {};
};

int main()
{
	long long n, k; cin >> n >> k;
	vector<point> p(n);
	for (auto& i : p) cin >> i.x >> i.y;
	sort(p.begin(), p.end(), [](point a, point b) {
		if (a.x < b.x)
			return true;
		return (a.x == b.x) && (a.y > b.y);
	});
	tree t = nullptr;
	for (long long i = 0; i < n; ++i) add(t, p[i].y);
	long long best = 0;
	for (long long i = 0; i < n;)
	{
		if (n - i < k) break;
		long long x = p[i].x;
		long long y = kmax(t, k);
		best = max(best, (long long)(x) * (long long)(y));
		while (i < n && p[i].x == x)
		{
			del(t, p[i].y);
			++i;
		}
	}
	cout << best << '\n';


	return 0;
}