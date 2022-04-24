#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<int>> g;
list<int> cycle;
vector<int> color;

int DFS(int v)
{
	color[v] = 1;
	for (auto&i : g[v])
	{
		if (color[i] == 0)
		{
			int res = DFS(i);
			if (res == -2)
				return -2;
			if (res != -1)
			{
				cycle.push_back(v);
				if (v != res)
					return res;
				else
					return -2;
			}
		}
		if (color[i] == 1)
		{
			cycle.push_back(v);
			return i;
		}
	}
	color[v] = 2;
	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2; 
		--v1;
		--v2;
		g[v1].push_back(v2);
	}
	color.resize(n, 0);
	for (int i = 0; i < n; ++i)
		if (color[i] == 0)
			if (DFS(i) == -2)
				break;
	if (cycle.size() == 0)
		cout << "NO";
	else
	{
		cout << "YES\n";
		reverse(cycle.begin(), cycle.end());
		for (auto&i : cycle) 
			cout << i + 1 << ' ';
	}

	return 0;
}