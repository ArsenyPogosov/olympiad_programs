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
	int x, y;
	Node* l, * r;
	Node() {};
	Node(int _x)
	{
		x = _x;
		y = (rand() << 15) + rand();
		l = r = nullptr;
	}
};

typedef Node* treap;

pair<treap, treap> split(treap t, int x)
{
	if (!t) return { nullptr, nullptr };

	pair<treap, treap> res;
	if (t->x <= x)
	{
		res = split(t->r, x);
		t->r = res.first;
		res.first = t;
	}
	if (t->x > x)
	{
		res = split(t->l, x);
		t->l = res.second;
		res.second = t;
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
	if (tl->y > tr->y)
	{
		tr->l = merge(tl, tr->l);
		return tr;
	}
}

treap insert(treap t, int x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, x);
	t2t3.first = new Node(x);
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
	return t;
}

int next(treap& t, int x)
{
	auto t1t2 = split(t, x - 1);
	auto it = t1t2.second;
	if (!it) return -1;
	while (it->l) it = it->l;
	t = merge(t1t2.first, t1t2.second);
	return it->x;
}

int main()
{
	srand(time(0) + 22322);
	treap t = nullptr;
	int n; cin >> n;
	int a = 0;
	for (int i = 0; i < n; ++i)
	{
		char h; int x; cin >> h >> x;
		if (h == '+') { t = insert(t, (x + a) % int(1e9)); a = 0; }
		if (h == '?') cout << (a = next(t, x)) << '\n';
	}

	return 0;
}