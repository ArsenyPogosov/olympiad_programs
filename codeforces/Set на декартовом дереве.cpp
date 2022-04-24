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
	long long x, y, sum, len;
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

pair<treap, treap> split(treap t, long long x)
{
	if (!t) return { nullptr, nullptr };

	pair<treap, treap> res;
	if (t->x <= x)
	{
		res = split(t->r, x);
		t->r = res.first;
		res.first = t;
		fix(res.first);
	}
	else
	{
		res = split(t->l, x);
		t->l = res.second;
		res.second = t;
		fix(res.second);
	}
	return res;
}

pair<treap, treap> splitk(treap t, long long k)
{
	if (!t) return { nullptr, nullptr };

	pair<treap, treap> res;
	if (tlen(t->l) >= k)
	{
		res = splitk(t->l, k);
		t->l = res.second;
		res.second = t;
		fix(res.second);
	}
	else
	{
		res = splitk(t->r, k - tlen(t->l) - 1);
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

treap insert(treap t, long long x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, x);
	t2t3.first = new Node(x);
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
	return t;
}

treap erase(treap t, long long x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, x);
	t2t3.first = nullptr;
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
	return t;
}

long long sum(treap& t, long long l, long long r)
{
	auto t1t23 = split(t, l - 1);
	auto t2t3 = split(t1t23.second, r);
	long long res = tsum(t2t3.first);
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
	return res;
}

long long sum(treap& t, long long x)
{
	auto t1t2 = splitk(t, x);
	long long res = tsum(t1t2.first);
	t = merge(t1t2.first, t1t2.second);
	return res;
}

int main()
{
	//srand(time(0) + 27682);
	treap t = nullptr;
	long long n; cin >> n;
	for (long long i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (s == "insert")
		{
			long long x;
			cin >> x;
			t = insert(t, x);
		}
		if (s == "erase")
		{
			long long x;
			cin >> x;
			t = erase(t, x);
		}
		if (s == "sum_min")
		{
			long long x;
			cin >> x;
			cout << sum(t, x) << '\n';
		}
		if (s == "sum")
		{
			long long l, r;
			cin >> l >> r;
			cout << sum(t, l, r) << '\n';
		}
	}

	return 0;
}