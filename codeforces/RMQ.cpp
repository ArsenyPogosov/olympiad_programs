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
	int min = 1000000001;
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
	res.min = min(a.min, b.min);
	return res;
}

void fix(int v, int l = -1, int r = -1)
{
	Tree[v] = merge(Tree[left(v)], Tree[right(v)]);
}

void build(vector<int>& mass, int v = 0, int l = 0, int r = -1)
{
	if (r == -1) { r = mass.size() - 1; Tree.resize(mass.size() * 4); }
	if (l == r)
	{
		Tree[v].min = mass[l];
		return;
	}
	build(mass, left(v), l, m(l, r));
	build(mass, right(v), m(l, r) + 1, r);
	fix(v);
}

void sett(int v, int l, int r, int p, int set)
{
	if (r < p || p < l) return;
	if (l == p && p == r) { Tree[v].min = set; return; }
	sett(left(v), l, m(l, r), p, set);
	sett(right(v), m(l, r) + 1, r, p, set);
	fix(v);
}

Node seg(int v, int l, int r, int ql, int qr)
{
	if (r < ql || qr < l) return Node();
	if (ql <= l && r <= qr) return Tree[v];
	auto la = seg(left(v), l, m(l, r), ql, qr);
	auto ra = seg(right(v), m(l, r) + 1, r, ql, qr);
	return merge(la, ra);
}

int query(int v, int l, int r, int ql, int qr)
{
	return seg(v, l, r, ql, qr).min;
}

int main()
{
	int n;
	cin >> n;
	vector<int> mass(n);
	for (auto& i : mass) cin >> i;
	build(mass);
	string h;
	int l, r;
	while (cin >> h >> l >> r)
	{
		if (h == "set")
		{
			sett(0, 0, n - 1, l - 1, r);
		}
		else
		{
			cout << query(0, 0, n - 1, l - 1, r - 1) << '\n';
		}
	}

	return 0;
}