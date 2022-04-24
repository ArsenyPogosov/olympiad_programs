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
	long long x, y, len;
	Node* l, * r;
	Node() {};
	Node(long long _x)
	{
		x = _x;
		len = 1;
		y = (rand() << 15) + rand();
		l = r = nullptr;
	}
};

typedef Node* treap;

long long tlen(treap t)
{
	return t ? t->len : 0;
}

void fix(treap t)
{
	if (!t) return;
	t->len = tlen(t->l) + tlen(t->r) + 1;
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

treap insert(treap t, int v, long long x)
{
	auto t1t2 = split(t, x - 1);
	t1t2.first = merge(t1t2.first, new Node(v));
	t = merge(t1t2.first, t1t2.second);
	return t;
}

int erase(treap& t, long long x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, 1);
	t = merge(t1t23.first, t2t3.second);
	return t2t3.first->x;
}

int get(treap& t, long long x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, 1);
	int res = t2t3.first->x;
	t = merge(merge(t1t23.first, t2t3.first), t2t3.second);
	return res;
}

vector<int> c, order;

int DFS(treap t)
{
	if (!t) return 0;
	if (DFS(t->l) != 0) return -1;

	int x = t->x;
	order.push_back(x);
	if (x != -1)
	{
		if (c[x] == -1) { cout << -1; return -1; }
		c[x] = -1;
	}

	return DFS(t->r);
}

int main()
{
	//double ga = clock();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0) + 27682);
	treap t = nullptr;
	long long n, m;
	cin >> n >> m; //n = 100000; m = 1000000;
	for (int i = 1; i <= n; ++i) t = insert(t, -1, i);
	vector<pair<int, int>> moves(m);
	for (auto& i : moves) cin >> i.first >> i.second; //i.first = i.second = 1;
	reverse(moves.begin(), moves.end());
	for (auto& i : moves)
	{
		int x = i.first, y = i.second;
		auto a = split(t, 1);
		if (a.first->x == -1) a.first->x = x;
		if (a.first->x != x) { cout << -1; return 0; }
		t = insert(a.second, x, y);
	}
	c.resize(n + 1), order.reserve(n);
	if (DFS(t) != 0) return 0;
	int tekmin = 1;
	for (int i = 0; i < n; ++i)
	{
		if (order[i] != -1) continue;
		while (c[tekmin] != 0) ++tekmin;
		order[i] = tekmin;
		c[tekmin] = -1;
	}
	for (auto& i : order) cout << i << ' ';
	//cout << (clock() - ga) / CLOCKS_PER_SEC << '\n';

	return 0;
}