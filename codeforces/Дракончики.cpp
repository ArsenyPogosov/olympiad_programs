//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260495/problem/A
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

int n, m;
vector<list<int>> Graph;
vector<int> p, used;
int T = 0;

bool DFS(int v)
{
	if (used[v] == T) return false;
	used[v] = T;
	for (auto& i : Graph[v])
		if (p[i] == -1 || DFS(p[i]))
		{
			p[i] = v;
			return true;
		}
	return false;
}

int main()
{
	cin >> n >> m; Graph.resize(n);
	for (auto& i : Graph)
	{
		int h; cin >> h;
		while (h)
		{
			i.push_back(h - 1);
			cin >> h;
		}
	}
	p.resize(m, -1); used.resize(n, -1);
	for (int i = 0; i < n; ++i)
		if (DFS(i))
			++T;
	list<pair<int, int>> ps;
	for (int i = 0; i < m; ++i)
		if (p[i] >= 0)
			ps.push_back({ p[i], i });
	cout << ps.size() << '\n';
	for (auto& i : ps) cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return 0;
}