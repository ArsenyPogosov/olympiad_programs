#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;
const long long INF = 1e9;

struct node
{
	long long x, y, rr, c, res, cnt;
	node* l, *r;
	node(long long x = 0, long long rr = 0, long long c = 0) : x(x), y(rand() * RAND_MAX + rand()), rr(rr), c(c), res(rr), cnt(c), l(nullptr), r(nullptr) {}
};
typedef node* treap;

long long Res(treap t)
{
	return t ? t->res : -INF;
}

long long Cnt(treap t)
{
	return t ? t->cnt : -INF;
}

void fix(treap t)
{
	if (!t) return;

	t->res = max({ Res(t->l), t->rr, Res(t->r) });
	t->cnt = 0;
	if (Res(t->l) == t->res) t->cnt += Cnt(t->l);
	if (t->rr == t->res) t->cnt += t->c;
	if (Res(t->r) == t->res) t->cnt += Cnt(t->r);
	t->cnt %= p;
}

void split(treap t, long long x, treap& t1, treap& t2)
{
	if (!t)
	{
		t1 = t2 = nullptr;
		return;
	}

	if (t->x <= x)
	{
		split(t->r, x, t->r, t2);
		fix(t);
		t1 = t;
	}
	else
	{
		split(t->l, x, t1, t->l);
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

void add(treap& t, long long x, long long rr, long long c)
{
	treap t1, t2; split(t, x, t1, t2);
	t = merge(t1, merge(new node(x, rr, c), t2));
}

pair<pair<long long, long long>, pair<long long, long long>> get(treap t, long long x)
{
	treap t1, t2; split(t, x, t1, t2);
	pair<pair<long long, long long>, pair<long long, long long>> res;
	res.first.first = Res(t1);
	res.first.second = Cnt(t1);
	res.second.first = Res(t2);
	res.second.second = Cnt(t2);
	t = merge(t1, t2);

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;

	vector<long long> gres(n, 1), gcnt(n, 1), dres(n, 1), dcnt(n, 1);
	treap g = new node(INF, 0, 1);
	for (long long i = n - 1; i >= 0; --i)
	{
		pair<long long, long long> h = get(g, a[i]).second;
		gres[i] = (h.first + 1) % p; gcnt[i] = h.second;
		add(g, a[i], gres[i], gcnt[i]);
	}
	g = new node(-INF, 0, 1);
	for (long long i = n - 1; i >= 0; --i)
	{
		pair<long long, long long> h = get(g, a[i] - 1).first;
		dres[i] = (h.first + 1) % p; dcnt[i] = h.second;
		add(g, a[i], dres[i], dcnt[i]);
	}

	long long res = 0, cnt = 0;
	for (long long i = 0; i < n; ++i)
	{
		if (res < gres[i] + dres[i] - 1)
			res = gres[i] + dres[i] - 1, cnt = 0;
		if (res == gres[i] + dres[i] - 1) cnt = (cnt + gcnt[i] * dcnt[i]) % p;
	}

	for (long long i = 0; i < n - res; ++i)
		cnt = (cnt * 2) % p;

	cout << res << ' ' << cnt << '\n';

	return 0;
}