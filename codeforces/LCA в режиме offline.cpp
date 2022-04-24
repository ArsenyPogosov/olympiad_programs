//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260272/problem/D
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

vector<list<int>> Graph;
vector<list<pair<int, int>>> LCA;
vector<int> res;

vector<int> dsu, r, a;

void build(int n)
{
	dsu.resize(n, -1); r.resize(n); a.resize(n);
	iota(a.begin(), a.end(), 0);
}

int get(int x)
{
	return (dsu[x] == -1 ? x : dsu[x] = get(dsu[x]));
}

void unite(int x, int y)
{
	x = get(x); y = get(y);
	if (x == y) return;
	a[x] = a[y];
	if (r[x] > r[y]) swap(x, y);
	dsu[x] = y;
	if (r[x] == r[y]) ++r[y];
}

vector<int> fire;

void LCADFS(int v, int p = -1)
{
	fire[v] = 1;

	for (auto& i : LCA[v])
		if (fire[i.first])
			res[i.second] = a[get(i.first)];
	for (auto& i : Graph[v])
		if (!fire[i])
			LCADFS(i, v);

	if (p >= 0) unite(v, p);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	Graph.resize(n);
	LCA.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	int a, b, count = 0;
	while (cin >> a >> b)
	{
		--a; --b;
		LCA[a].push_back({ b, count });
		LCA[b].push_back({ a, count });
		++count;
	}
	res.resize(count);
	fire.resize(n);
	build(n);
	LCADFS(0);
	for (auto& i : res) cout << i + 1 << '\n';

	return 0;
}