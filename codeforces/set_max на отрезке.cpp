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

const pair<int, int> nitral = { 1000000001, 0 };

struct Node {
	int min, max;
	int set = -1;
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

void fix(int v, int l = -1, int r = -1)
{
	Tree[v].min = min(Tree[left(v)].min, Tree[right(v)].min);
	Tree[v].max = max(Tree[left(v)].max, Tree[right(v)].max);
}

void build(vector<int>& mass, int v = 0, int l = 0, int r = -1)
{
	if (r == -1) { r = mass.size() - 1; Tree.resize(mass.size() * 4); }
	if (l == r)
	{
		Tree[v].min = Tree[v].max = mass[l];
		return;
	}
	build(mass, left(v), l, m(l, r));
	build(mass, right(v), m(l, r) + 1, r);
	fix(v);
}

void sett(int v, int set)
{
	Tree[v].set = max(Tree[v].set, set);
	Tree[v].min = max(Tree[v].min, set);
	Tree[v].max = max(Tree[v].max, set);
}

void push(int v, int l = -1, int r = -1)
{
	if (Tree[v].set == -1) return;

	sett(left(v), Tree[v].set);
	sett(right(v), Tree[v].set);
	Tree[v].set = -1;
}

void sett(int v, int l, int r, int ql, int qr, int set)
{
	if (r < ql || qr < l) return;
	if (ql <= l && r <= qr) { sett(v, set); return; }
	push(v);
	sett(left(v), l, m(l, r), ql, qr, set);
	sett(right(v), m(l, r) + 1, r, ql, qr, set);
	fix(v);
}

pair<int, int> query(int v, int l, int r, int ql, int qr)
{
	if (r < ql || qr < l) return nitral;
	if (ql <= l && r <= qr) return {Tree[v].min, Tree[v].max};
	push(v);
	auto la = query(left(v), l, m(l, r), ql, qr);
	auto ra = query(right(v), m(l, r) + 1, r, ql, qr);
	return { min(la.first, ra.first), max(la.second, ra.second) };
}

int main()
{
	int n;
	cin >> n;
	vector<int> mass(n);
	for (auto& i : mass) cin >> i;
	build(mass);
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		if (s == "ask")
		{
			int l, r;
			cin >> l >> r;
			auto a = query(0, 0, n - 1, l - 1, r - 1);
			cout << a.second - a.first << '\n';
		}
		else
		{
			int l, r, s;
			cin >> l >> r >> s;
			sett(0, 0, n - 1, l - 1, r - 1, s);
		}
	}

	return 0;
}