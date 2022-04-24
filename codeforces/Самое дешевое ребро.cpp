//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260272/problem/K
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

const int INF = 1000000000;

int n;
vector<list<pair<int, int>>> Graph;
vector<vector<int>> up, mup;
vector<int> tin, tout;
int t = 0;

void UPDFS(int v, int cost = -1, int p = -1)
{
	tin[v] = ++t;
	if (p >= 0)
	{
		up[0][v] = p;
		mup[0][v] = cost;
		for (int i = 1; i < 30; ++i)
		{
			up[i][v] = up[i - 1][up[i - 1][v]];
			mup[i][v] = min(mup[i - 1][up[i - 1][v]], mup[i - 1][v]);
		}
	}
	for (auto& i : Graph[v])
		if (i.first != p)
			UPDFS(i.first, i.second, v);
	tout[v] = t++;
}

void buildUP(int v = 0)
{
	up.resize(30, vector<int>(n, v));
	mup.resize(30, vector<int>(n));
	tin.resize(n); tout.resize(n);
	UPDFS(v);
}

bool arc(int a, int b)
{
	return (tin[a] <= tin[b]) && (tout[b] <= tout[a]);
}

int mLCA(int a, int b)
{
	int res = INF;
	for (int i = 29; i >= 0; --i)
		if (!arc(up[i][a], b))
		{
			res = min(res, mup[i][a]);
			a = up[i][a];
		}
	if (!arc(a, b))
	{
		res = min(res, mup[0][a]);
		a = up[0][a];
	}
	swap(a, b);
	for (int i = 29; i >= 0; --i)
		if (!arc(up[i][a], b))
		{
			res = min(res, mup[i][a]);
			a = up[i][a];
		}
	if (a != b) res = min(res, mup[0][a]);
	return res;
}

int main()
{
	cin >> n;
	Graph.resize(n);
	for (int i = 1; i < n; ++i)
	{
		int x, y; cin >> x >> y; --x;
		Graph[x].push_back({ i, y });
		Graph[i].push_back({ x, y });
	}
	buildUP();
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y; cin >> x >> y;
		cout << mLCA(x - 1, y - 1) << '\n';
	}

	return 0;
}