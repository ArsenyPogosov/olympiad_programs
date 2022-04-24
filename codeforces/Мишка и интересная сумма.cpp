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
	int sum = 0;
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
	res.sum = a.sum ^ b.sum;
	return res;
}

void fix(int v, int l = -1, int r = -1)
{
	Tree[v] = merge(Tree[left(v)], Tree[right(v)]);
}

void build(vector<int>& mass, int v = 0, int l = 0, int r = -1)
{
	if (r == -1) Tree.resize(mass.size() * 4);
	if (r == -1) r = mass.size() - 1;

	if (l == r) { Tree[v].sum = mass[l]; return; }
	build(mass, left(v), l, m(l, r));
	build(mass, right(v), m(l, r) + 1, r);
	fix(v);
}

void sett(int v, int l, int r, int p, int set)
{
	if (r < p || p < l) return;
	if (l == p && p == r) { Tree[v].sum = set; return; }
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

int Query(int v, int l, int r, int lq, int rq)
{
	auto res = seg(v, l, r, lq, rq);
	return res.sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	build(a);

	int m; cin >> m;
	vector<pair<int, int>> query(m);
	for (auto& i : query) cin >> i.first >> i.second;
	vector<int> order(m);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		pair<int, int> aa = { query[a].second, query[a].first };
		pair<int, int> bb = { query[b].second, query[b].first };
		return aa < bb;
		});

	vector<int> ans(m);
	map<int, int> lpos;
	vector<int> tsum(n);
	int tr = -1;
	for (auto& p : order)
	{
		int l = query[p].first - 1, r = query[p].second - 1;
		while (tr < r)
		{
			++tr;
			if (lpos.find(a[tr]) != lpos.end()) sett(0, 0, n - 1, lpos[a[tr]], 0);
			lpos[a[tr]] = tr;
			sett(0, 0, n - 1, tr, a[tr]);
			if (tr == 0)
				tsum[tr] = a[tr];
			else
				tsum[tr] = tsum[tr - 1] ^ a[tr];
		}
		ans[p] = Query(0, 0, n - 1, l, r) ^ tsum[r] ^ (l > 0 ? tsum[l - 1] : 0);
	}
	for(auto&i: ans) cout << i << '\n';

	return 0;
}