//source: http://codeforces.com/problemset/problem/1217/E
//status: throwed

#include<bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");s
#define cin fin
#define cout fout
#endif
#pragma endregion

const int INF = 1000000001;

struct node
{
	int min1[9], min2[9];
	node()
	{
		for (int i = 0; i < 9; ++i) min1[i] = min2[i] = INF;
	}
	node(int n)
	{
		for (int i = 0; i < 9; ++i) min1[i] = min2[i] = INF;
		int nn = n;
		for (int i = 0; nn != 0; nn /= 10, ++i)
			if (nn % 10 != 0)
				min1[i] = n;
	}
};

node tree[8*100000+5];

void sum(node &res, node &a, node &b)
{
	for (int i = 0; i < 9; ++i)
	{
		int h[4]{ a.min1[i], a.min2[i], b.min1[i], b.min2[i] };
		for (int i = 0; i < 2; ++i)
			for (int j = 2; j >= 0; --j)
				if (h[j] > h[j + 1]) swap(h[j], h[j + 1]);
		res.min1[i] = h[0];
		res.min2[i] = h[1];
	}
}

void fix(int v)
{
	sum(tree[v], tree[v << 1], tree[(v << 1) + 1]);
}

void change(int v, int l, int r, int pos, int n)
{
	if (l == r)
	{
		tree[v] = node(n);
		return;
	}
	int m = (l + r) >> 1;
	if (pos <= m)
		change((v << 1), l, m, pos, n);
	else
		change((v << 1) + 1, m + 1, r, pos, n);
	fix(v);
}

void min(node &res, int v, int l, int r, int a, int b)
{
	if (r < a || b < l)
	{
		res = node(); return;
	}
	if (a <= l && r <= b)
	{
		res = tree[v]; return;
	}

	int m = (l + r) >> 1;
	node h1, h2;
	min(h1, v << 1, l, m, a, b);
	min(h2, (v << 1) + 1, m + 1, r, a, b);

	sum(res, h1, h2);
}

int ans(int l, int r, int n)
{
	node h;
	min(h, 1, 0, n - 1, l, r);
	int res = INF * 2;
	for (int i = 0; i < 9; ++i)
		if (h.min1[i] < INF && h.min2[i] < INF)
			res = min(res, h.min1[i] + h.min2[i]);
	if (res == INF * 2)
		return -1;
	return res;
}

int main()
{
	srand(time(0));
	int n, m;
	//cin >> n >> m;
	n = 200000;
	m = 200000;

	for (int i = 0; i < n; ++i)
	{
		int h;
		//cin >> h;
		h = rand() % 100 + 1;
		change(1, 0, n - 1, i, h);
	}

	for (int i = 0; i < m; ++i)
	{
		int h, l, r;
		//cin >> h;
		h = rand() % 2 + 1;
		if (h == 1)
		{
			int p, m;
			//cin >> p >> m; --p;
			p = rand() % n;
			m = rand() % 100;
			change(1, 0, n - 1, p, m);
		}
		if (h == 2)
		{
			int l, r;
			cin >> l >> r; --l; --r;
			l = rand() % n;
			r = rand() % (n - l) + l;
			cout << ans(l, r, n) << '\n';
		}
	}

	return 0;
}