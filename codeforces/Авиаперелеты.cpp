//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260097/problem/G
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("avia.in");
ofstream fout("avia.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int n;
vector<vector<int>> Graph;
vector<int> fire;

void DFS(int v, int m)
{
	fire[v] = true;
	for (int i = 0; i < n; ++i)
		if (!fire[i] && Graph[v][i] <= m)
			DFS(i, m);
}

void RDFS(int v, int m)
{
	fire[v] = true;
	for (int i = 0; i < n; ++i)
		if (!fire[i] && Graph[i][v] <= m)
			RDFS(i, m);
}

int main()
{
	cin >> n;
	Graph.resize(n, vector<int>(n));
	for (auto& i : Graph)
		for (auto& j : i)
			cin >> j;
	int l = -1, r = 1e9 + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		fire.assign(n, false);
		DFS(0, m);
		bool flag = false;
		for (auto& i : fire) 
			if (!i) 
			{ 
				l = m; 
				flag = true;
				continue; 
			}
		if (flag) continue;
		fire.assign(n, false);
		RDFS(0, m);
		for (auto& i : fire)
			if (!i)
			{
				l = m;
				flag = true;
				continue;
			}
		if (flag) continue;
		r = m;
	}
	cout << r;

	return 0;
}