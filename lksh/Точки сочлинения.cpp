#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<int>> g;
vector<int> color, tin, up;
int t;
set<int> cutPoint;

void DFS(int v, int p = -1)
{
	tin[v] = t++;
	color[v] = 1;
	up[v] = tin[v];
	int count = 0;
	for (auto&i : g[v])
		if (i != p)
		{
			if (color[i] == 1)
				up[v] = min(up[v], tin[i]);
			if (color[i] == 0)
			{
				DFS(i, v);
				up[v] = min(up[v], up[i]);
				if (p != -1)
					if (up[i] >= tin[v])
						cutPoint.insert(v);
				++count;
			}
		}
	if (p == -1 && count > 1)
		cutPoint.insert(v);
	color[v] = 2;
}

int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	color.resize(n);
	tin.resize(n);
	up.resize(n);
	for (int i = 0; i < n; ++i)
		if (color[i] == 0)
			DFS(i, -1);

	cout << cutPoint.size() << '\n';
	for (auto&i : cutPoint)
		cout << i + 1 << ' ';

	return 0;
}