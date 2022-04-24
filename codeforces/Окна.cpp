//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258488/problems
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
	int max = -1, index = -1, add = 0;
};

vector<Node> Tree;

int left(int v)
{
	return v * 2 + 1;
}

int right(int v)
{
	return v * 2 + 2;
}

int m(int l, int r)
{
	return (l + r) / 2;
}

Node merge(Node a, Node b)
{
	Node res;
	if (a.max < b.max) swap(a, b);
	res.max = a.max;
	res.index = a.index;
	return res;
}

void fix(int v, int l = -1, int r = -1)
{
	Tree[v] = merge(Tree[left(v)], Tree[right(v)]);
}

void build(int n, int v = 0, int l = 0, int r = -1)
{
	if (r == -1) r = n - 1;
	if (n != -1) Tree.resize(n * 4);

	if (l == r) { Tree[v].max = 0; Tree[v].index = l; return; }
	build(-1, left(v), l, m(l, r));
	build(-1, right(v), m(l, r) + 1, r);
	fix(v);
}

void sett(int v, int l, int r, int add)
{
	Tree[v].add += add;
	Tree[v].max += add;
}

void push(int v, int l, int r)
{
	sett(left(v), l, m(l, r), Tree[v].add);
	sett(right(v), m(l, r) + 1, r, Tree[v].add);
	Tree[v].add = 0;
}

void sett(int v, int l, int r, int ql, int qr, int add)
{
	if (r < ql || qr < l) return;
	if (ql <= l && r <= qr) { sett(v, l, r, add); return; }
	push(v, l, r);
	sett(left(v), l, m(l, r), ql, qr, add);
	sett(right(v), m(l, r) + 1, r, ql, qr, add);
	fix(v);
}

Node seg(int v, int l, int r, int ql, int qr)
{
	if (r < ql || qr < l) return Node();
	if (ql <= l && r <= qr) return Tree[v];
	push(v, l, r);
	auto la = seg(left(v), l, m(l, r), ql, qr);
	auto ra = seg(right(v), m(l, r) + 1, r, ql, qr);
	return merge(la, ra);
}

pair<int, int> max(int v, int l, int r, int lq, int rq)
{
	auto res = seg(v, l, r, lq, rq);
	return { res.max, res.index };
}

int main()
{
	int n = 4 * 100000 + 5, m;
	cin >> m;
	build(n);
	vector<list<pair<int, int>>> os(n), cs(n);
	for (int i = 0; i < m; ++i)
	{
		int x1, y1, x2, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 2 * 100000; x2 += 2 * 100000; y1 += 2 * 100000; y2 += 2 * 100000;
		os[x1].push_back({ y1, y2 });
		cs[x2].push_back({ y1, y2 });
	}
	int bc = -1, bx, by;
	for (int i = 0; i < n; ++i)
	{
		for (auto& i : os[i]) sett(0, 0, n - 1, i.first, i.second, 1);
		auto a = Tree[0];
		if (bc < a.max)
		{
			bc = a.max;
			bx = i - 2 * 100000;
			by = a.index - 2 * 100000;
		}
		for (auto& i : cs[i]) sett(0, 0, n - 1, i.first, i.second, -1);
	}
	cout << bc << '\n' << bx << ' ' << by;

	return 0;
}