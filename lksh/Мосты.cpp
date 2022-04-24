#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<pair<int, int>>> g;
vector<int> color, tin, up;
int t;
list<int> bridge;

void DFS(int v, int p)
{
	tin[v] = t++;
	color[v] = 1;
	up[v] = tin[v];
	for (auto&i : g[v])
		if (i.first != p)
		{
			if (color[i.first] == 1)
				up[v] = min(up[v], tin[i.first]);
			if (color[i.first] == 0)
			{
				DFS(i.first, v);
				up[v] = min(up[v], up[i.first]);
				if (up[i.first] > tin[v])
					bridge.push_back(i.second);
			}
		}
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
		g[a].push_back({ b, i });
		g[b].push_back({ a, i });
	}
	color.resize(n);
	tin.resize(n);
	up.resize(n);
	for (int i = 0; i < n; ++i)
		if (color[i] == 0)
			DFS(i, -1);

	bridge.sort();
	cout << bridge.size() << '\n';
	for (auto&i : bridge)
		cout << i << ' ';

	return 0;
}