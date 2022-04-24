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
vector<vector<int>> node;
vector<int> color, tin, up;
int t;
set<int> cutPoint;

void DFS(int v, int p = -1)
{
	tin[v] = t++;
	color[v] = 1;
	up[v] = tin[v];
	int count = 0;
	for (auto& j : node[v])
		for (auto it = )
		{
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
	node.resize(m, vector<int>(3));
	for (int i = 0; i < m; ++i)
	{
		cin >> node[i][0] >> node[i][1] >> node[i][2];
		--node[i][0];
		--node[i][1];
		--node[i][2];
		g[node[i][0]].push_back(i);
		g[node[i][1]].push_back(i);
		g[node[i][2]].push_back(i);
	}
	color.resize(m);
	tin.resize(m);
	up.resize(m);
	for (int i = 0; i < m; ++i)
		if (color[i] == 0)
			DFS(i, -1);

	cout << cutPoint.size() << '\n';
	for (auto&i : cutPoint)
		cout << i + 1 << ' ';

	return 0;
}