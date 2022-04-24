//source: https://codeforces.com/contest/1260/problem/D
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

struct Node
{
	int sum;
	bool change;
	Node() { sum = change = 0; }
};

int n;
vector<Node> tree;

void build()
{
	tree.resize(n * 4 + 15, Node());
}

void push(int v, int l, int r)
{
	if (!tree[v].change) return;
	tree[v * 2 + 1].change = true;
	tree[v * 2 + 2].change = true;
	int m = (l + r) / 2;
	tree[v * 2 + 1].sum = (m - l) + 1;
	tree[v * 2 + 2].sum = (r - m);
	tree[v].change = false;
}

void fix(int v, int l, int r)
{
	tree[v].sum = tree[v * 2 + 1].sum + tree[v * 2 + 2].sum;
}

int Sum()
{
	return tree[0].sum;
}

void Change(int v, int l, int r, int L, int R)
{
	if (r < L || R < l) return;
	if (L <= l && r <= R)
	{
		tree[v].sum = (r - l + 1);
		tree[v].change = true;
		return;
	}
	int m = (l + r) / 2;
	push(v, l, r);
	Change(v * 2 + 1, l, m, L, R);
	Change(v * 2 + 2, m + 1, r, L, R);
	fix(v, l, r);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, k, t; cin >> m >> n >> k >> t;
	build();
	vector<int> a(m);
	for (auto& i : a) cin >> i;
	vector<pair<int, pair<int, int>>> lov(k);
	for (auto& i : lov) cin >> i.second.first >> i.second.second >> i.first;
	sort(lov.begin(), lov.end(), greater<pair<int, pair<int, int>>>());
	int maxL = 2 * 1e5 + 5, i = 0;
	while (n + 1 + Sum() * 2 <= t)
	{
		--maxL;
		if (i >= k)
		{
			cout << m; return 0;
		}
		while (maxL < lov[i].first)
		{
			Change(0, 0, n, lov[i].second.first, lov[i].second.second);
			++i;
		}
	}
	++maxL;
	int count = 0;
	for (auto& i : a) if (i >= maxL) ++count;
	cout << count;

	return 0;
}