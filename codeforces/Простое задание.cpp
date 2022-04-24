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
	string s;
	int reg = -1;
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
	res.s = a.s + b.s;
	return res;
}

void fix(int v, int l = -1, int r = -1)
{
	Tree[v] = merge(Tree[left(v)], Tree[right(v)]);
}

void build(string& mass, int v = 0, int l = 0, int r = -1)
{
	if (r == -1) { r = mass.size() - 1; Tree.resize(mass.size() * 4); }
	if (l == r) { Tree[v].s = mass[l]; return; }
	build(mass, left(v), l, m(l, r));
	build(mass, right(v), m(l, r) + 1, r);
	fix(v);
}

void sett(int v, int l, int r, int set)
{
	Tree[v].reg = set;
	if (set == 0) sort(Tree[v].s.begin(), Tree[v].s.end(), greater<char>());
	if (set == 1) sort(Tree[v].s.begin(), Tree[v].s.end());
}

void push(int v, int l, int r)
{
	if (Tree[v].reg == -1) return;

	sett(left(v), l, m(l, r), Tree[v].reg);
	sett(right(v), m(l, r) + 1, r, Tree[v].reg);
	Tree[v].reg = -1;
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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	build(s);
	for (int i = 0; i < q; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		sett(0, 0, n - 1, a - 1, b - 1, c);
	}
	cout << Tree[0].s;

	return 0;
}