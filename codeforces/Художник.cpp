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
	int sum = 0, count = 0, set = -1;
	bool l = false, r = false;
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
	res.sum = a.sum + b.sum;
	res.count = a.count + b.count;
	if (a.r && b.l) --res.count;
	res.l = a.l; res.r = b.r;
	return res;
}

void fix(int v, int l = -1, int r = -1)
{
	Tree[v] = merge(Tree[left(v)], Tree[right(v)]);
}

void build(vector<int>& mass, int v = 0, int l = 0, int r = -1)
{
	if (r == -1) { r = mass.size() - 1; Tree.resize(mass.size() * 4); }
}

void sett(int v, int l, int r, int set)
{
	Tree[v].set = set;
	if (set == 1)
	{
		Tree[v].sum = (r - l + 1);
		Tree[v].count = 1;
		Tree[v].l = Tree[v].r = true;
	}
	else
	{
		Tree[v].sum = 0;
		Tree[v].count = 0;
		Tree[v].l = Tree[v].r = false;
	}
}

void push(int v, int l, int r)
{
	if (Tree[v].set == -1) return;

	sett(left(v), l, m(l, r), Tree[v].set);
	sett(right(v), m(l, r) + 1, r, Tree[v].set);
	Tree[v].set = -1;
}

void sett(int v, int l, int r, int ql, int qr, int set)
{
	if (r < ql || qr < l) return;
	if (ql <= l && r <= qr) { sett(v, l, r, set); return; }
	push(v, l, r);
	sett(left(v), l, m(l, r), ql, qr, set);
	sett(right(v), m(l, r) + 1, r, ql, qr, set);
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

int main()
{
	int n;
	cin >> n;
	vector<int> mass(1000002);
	build(mass);
	for (int i = 0; i < n; ++i)
	{
		char h;
		int x, l;
		cin >> h >> x >> l; x += 500000;
		sett(0, 0, 1000001, x, x + l - 1, h == 'B' ? 1 : 0);
		cout << Tree[0].count << ' ' << Tree[0].sum << '\n';
	}

	return 0;
}