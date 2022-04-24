//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260272/problem/B
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

int n;
vector<list<int>> Graph;
vector<vector<int>> up;

void UDFS(int v, int p = -1)
{
	if (p >= 0)
	{
		up[v][0] = p;
		for (int i = 1; i < 30; ++i)
			up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (auto& i : Graph[v])
		if (i != p)
			UDFS(i, v);
}

void build(int v)
{
	up.resize(n, vector<int>(30, v));
	UDFS(v);
}

int LA(int v, int k)
{
	if (k == 0) return v;
	for (int i = 29; i >= 0; --i)
		if (k >= (1 << i))
			return LA(up[v][i], k - (1 << i));
}

int main()
{
	cin >> n;
	Graph.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y; cin >> x >> y; --x; --y;
		Graph[x].push_back(y);
		Graph[y].push_back(x);
	}
	build(0);
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int n, k; cin >> n >> k;
		cout << LA(n - 1, k) + 1 << '\n';
	}

	return 0;
}