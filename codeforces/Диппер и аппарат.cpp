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

struct query {
	int type, l, r, i, ind;
	string s;
	query() {}
	query(int _i, int _ind, int x, int y)
	{
		type = 2;
		i = _i;
		ind = _ind;
		l = x;
		r = y;
	}
	query(int _l, int _r, string _s)
	{
		type = 1;
		l = _l;
		r = _r;
		s = _s;
	}
};

vector<query> q;

struct Node {
	pair<int, int> x;
	int y;
	int L, R, count;
	string res, add;
	Node* l, * r;
	Node() {};
	Node(int _x, int ind, int _L, int _R)
	{
		x = { _x, ind };
		L = _L;
		R = _R;
		count = 0;
		res = add = "";
		y = (rand() << 15) + rand();
		l = r = nullptr;
	}
};

typedef Node* treap;

void tadd(treap t, string add)
{
	if (!t) return;
	if (add == "") return;

	int it = max(0, min(t->L - t->count - 1, (int)(add.size())));
	t->count += it;
	for (; it < add.size() && t->count < t->R; ++it)
	{
		t->res += add[it]; ++t->count;
	}
	t->add += add;
}

void push(treap t)
{
	if (!t) return;
	tadd(t->l, t->add);
	tadd(t->r, t->add);
	t->add = "";
}

pair<treap, treap> split(treap t, pair<int, int> x)
{
	if (!t) return { nullptr, nullptr };

	pair<treap, treap> res;
	push(t);
	if (t->x <= x)
	{
		res = split(t->r, x);
		t->r = res.first;
		res.first = t;
	}
	else
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
		push(tl);
		tl->r = merge(tl->r, tr);
		return tl;
	}
	else
	{
		push(tr);
		tr->l = merge(tl, tr->l);
		return tr;
	}
}

treap insert(treap t, int x, int ind, int L, int R)
{
	auto t1t23 = split(t, { x, ind - 1 });
	auto t2t3 = split(t1t23.second, { x, ind });
	t2t3.first = new Node(x, ind, L, R);
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
	return t;
}

int main()
{
	srand(time(0) + 27682);
	treap t = nullptr;
	int n, m; cin >> n >> m;
	vector<query> q(m);
	for (int i = 0; i < m; ++i)
	{
		int h;
		cin >> h;
		if (h == 1)
		{
			int l, r; string s;
			cin >> l >> r >> s;
			q[i] = query(l, r, s);
		}
		if (h == 2)
		{
			int ii, x, y;
			cin >> ii >> x >> y;
			q[i] = query(ii, i, x, y);
			t = insert(t, ii, i, x, y);
		}
	}
	for (auto& i : q)
	{
		if (i.type == 1)
		{
			auto t1t23 = split(t, { i.l - 1, 1000000 });
			auto t2t3 = split(t1t23.second, { i.r, 1000000 });
			tadd(t2t3.first, i.s);
			t = merge(merge(t1t23.first, t2t3.first), t2t3.second);
		}
		if (i.type == 2)
		{
			auto t1t23 = split(t, { i.i, i.ind - 1 });
			auto t2t3 = split(t1t23.second, { i.i, i.ind });
			cout << t2t3.first->res << '\n';
			t = merge(merge(t1t23.first, t2t3.first), t2t3.second);
		}
	}

	return 0;
}