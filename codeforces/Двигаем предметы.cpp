//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260495/problem/H
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

bool br(pair<int, int> b, pair<int, int> e, int v, double t)
{
	int x = abs(b.first - e.first), y = abs(b.second - e.second);
	return (x * x + y * y <= t * t * v * v);
}

int main()
{
	cin >> n; m = n;
	vector<int> v(n);
	vector<pair<int, int>> bp(n), ep(n);
	for (int i = 0; i < n; ++i)
		cin >> bp[i].first >> bp[i].second >> v[i];
	for (int i = 0; i < n; ++i)
		cin >> ep[i].first >> ep[i].second;
	double l = 0, r = 5000;
	while (r - l > 0.000001)
	{
		double M = (l + r) / 2;
		Graph.assign(n, {});
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (br(bp[i], ep[j], v[i], M))
					Graph[i].push_back(j);

		p.assign(m, -1); used.assign(n, -1);
		for (int i = 0; i < n; ++i)
			if (DFS(i))
				++T;

		bool flag = true;
		for (auto&i: p)
			if (i < 0)
			{
				l = M;
				flag = false;
				break;
			}
		if (flag)
			r = M;
	}
	cout << fixed << setprecision(16) << r;

	return 0;
}