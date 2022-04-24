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
	long long x, y, min;
	Node* l, * r;
	Node() {};
	Node(long long _x)
	{
		x = _x;
		min = x;
		y = (rand() << 15) + rand();
		l = r = nullptr;
	}
};

typedef Node* treap;

int tmin(treap t)
{
	return t ? t->min : 1000000000;
}

void fix(treap t)
{
	if (!t) return;
	t->min = tmin(t->l) + tmin(t->r);
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

treap merge(treap tl, treap tr)
{
	if (!tl) return tr;
	if (!tr) return tl;

	if (tl->y <= tr->y)
	{
		tl->r = merge(tl->r, tr);
		return tl;
	}
	else
	{
		tr->l = merge(tl, tr->l);
		return tr;
	}
}

treap unite(treap tl, treap tr)
{
	treap res = nullptr;
	while (true)
	{
		if (!tl) return merge(res, tr);
		if (!tr) return merge(res, tl);

		if (tl->min < tr->min)
		{
			auto a = split(tl, tr->min);
			tl = a.second;
			res = merge(res, a.first);
		}
		else
		{
			auto a = split(tr, tl->min);
			tr = a.second;
			res = merge(res, a.first);
		}
	}
	return res;
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

int main()
{
	srand(time(0) + 27682);
	long long n; cin >> n;
	vector<treap> t(n);
	for (long long i = 0; i < n; ++i)
	{
		int k; cin >> k;
		for (int i = 0; i < k; ++i)
		{
			int h; cin >> h;
			t[i] = insert(t[i], h);
		}
	}

	return 0;
}