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
	long long x, y, len, min;
	Node* l, * r;
	Node() {};
	Node(long long _x)
	{
		x = _x;
		min = x;
		len = 1;
		y = (rand() << 15) + rand();
		l = r = nullptr;
	}
};

typedef Node* treap;

long long tmin(treap t)
{
	return t ? t->min : 1000000005;
}

long long tlen(treap t)
{
	return t ? t->len : 0;
}

void fix(treap t)
{
	if (!t) return;
	t->len = tlen(t->l) + tlen(t->r) + 1;
	t->min = min({ tmin(t->l), tmin(t->r), t->x });
}

pair<treap, treap> split(treap t, long long k)
{
	if (!t) return { nullptr, nullptr };

	pair<treap, treap> res;
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
		tl->r = merge(tl->r, tr);
		fix(tl);
		return tl;
	}
	else
	{
		tr->l = merge(tl, tr->l);
		fix(tr);
		return tr;
	}
}

treap insert(treap t, long long v, long long x)
{
	auto t1t2 = split(t, x - 1);
	t1t2.first = merge(t1t2.first, new Node(v));
	t = merge(t1t2.first, t1t2.second);
	return t;
}

long long rmq(treap &t, long long l, long long r)
{
	auto t1t23 = split(t, l - 1);
	auto t2t3 = split(t1t23.second, r - l + 1);
	long long res = tmin(t2t3.first);
	t = merge(merge(t1t23.first, t2t3.first), t2t3.second);
	return res;
}

int main()
{
	srand(time(0) + 27682);
	treap t = nullptr;
	long long n; cin >> n;
	for (long long i = 0; i < n; ++i)
	{
		char h;
		long long a, b;
		cin >> h >> a >> b;
		if (h == '?') cout << rmq(t, a, b) << '\n';
		if (h == '+') t = insert(t, b, a + 1);
	}

	return 0;
}