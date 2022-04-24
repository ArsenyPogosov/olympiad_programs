#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<int>> g1, g2;
vector<bool> used, depo;

void dfs1(int v)
{
	used[v] = true;
	for (auto& i : g1[v])
		if (!used[i])
			dfs1(i);
}

void dfs2(int v)
{
	used[v] = true;
	for (auto& i : g2[v])
	{
		if (depo[i])
			depo[i] = false;
		if (!used[i])
			dfs2(i);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	g1.resize(n);
	g2.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g1[b - 1].push_back(a - 1);
	}

	used.resize(n);
	vector<bool> cond(n);
	for (int i = 0; i < n; ++i)
		if (!used[i])
		{
			cond[i] = true;
			dfs1(i);
		}

	for (int i = 0; i < n; ++i)
		if (cond[i])
			for (auto& j : g1[i])
				if (cond[j])
					g2[i].push_back(j);

	depo.resize(n);
	used.assign(n, false);
	for (int i = 0; i < n; ++i)
		if (!used[i] && cond[i])
		{
			dfs2(i);
			depo[i] = true;
		}

	int count = 0;
	for (auto i : depo)
		if (i)
			++count;
	cout << count;

	return 0;
}