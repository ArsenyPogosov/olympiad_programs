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
	long long x, y, len, sum;
	Node* l, * r;
	Node() {};
	Node(long long _x)
	{
		x = _x;
		sum = x;
		len = 1;
		y = (rand() << 15) + rand();
		l = r = nullptr;
	}
};

typedef Node* treap;

long long tsum(treap t)
{
	return t ? t->sum : 0;
}

long long tlen(treap t)
{
	return t ? t->len : 0;
}

void fix(treap t)
{
	if (!t) return;
	t->len = tlen(t->l) + tlen(t->r) + 1;
	t->sum = tsum(t->l) + tsum(t->r) + t->x;
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

long long sum(treap& nt, treap& ct, long long l, long long r)
{
	long long cl = (l + 1) / 2, cr = r / 2, nl = l / 2 + 1, nr = (r + 1) / 2;
	vector<treap> ntp(3), ctp(3);
	auto a = split(nt, nl - 1);
	auto b = split(a.second, nr - nl + 1);
	ntp[0] = a.first; ntp[1] = b.first; ntp[2] = b.second;
	auto c = split(ct, cl - 1);
	auto d = split(c.second, cr - cl + 1);
	ctp[0] = c.first; ctp[1] = d.first; ctp[2] = d.second;
	long long res = tsum(ntp[1]) + tsum(ctp[1]);
	nt = merge(merge(ntp[0], ntp[1]), ntp[2]);
	ct = merge(merge(ctp[0], ctp[1]), ctp[2]);
	return res;
}

void swap(treap& nt, treap& ct, long long l, long long r)
{
	long long cl = (l + 1) / 2, cr = r / 2, nl = l / 2 + 1, nr = (r + 1) / 2;
	vector<treap> ntp(3), ctp(3);
	auto a = split(nt, nl - 1);
	auto b = split(a.second, nr - nl + 1);
	ntp[0] = a.first; ntp[1] = b.first; ntp[2] = b.second;
	auto c = split(ct, cl - 1);
	auto d = split(c.second, cr - cl + 1);
	ctp[0] = c.first; ctp[1] = d.first; ctp[2] = d.second;
	swap(ntp[1], ctp[1]);
	nt = merge(merge(ntp[0], ntp[1]), ntp[2]);
	ct = merge(merge(ctp[0], ctp[1]), ctp[2]);

}

int main()
{
	srand(time(0) + 27682);
	long long count = 0;
	while (true)
	{
		++count;
		treap nt = nullptr, ct = nullptr;
		long long n, m; cin >> n >> m;
		if (n == m && m == 0) break;
		for (long long i = 1; i <= n; ++i)
		{
			long long h; cin >> h;
			if (i % 2 == 1) nt = insert(nt, h, i / 2 + 1);
			if (i % 2 == 0) ct = insert(ct, h, i / 2);
		}
		if (count != 1) cout << '\n';
		cout << "Swapper " << count << ":\n";
		for (long long i = 0; i < m; ++i)
		{
			long long r, a, b;
			cin >> r >> a >> b;
			if (r == 1) swap(nt, ct, a, b);
			if (r == 2) cout << sum(nt, ct, a, b) << '\n';
		}
	}

	return 0;
}