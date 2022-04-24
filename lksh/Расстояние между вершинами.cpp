#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<pair<int, int>>> g;

const int INF = 1000000000;

int main()
{
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	--a;
	--b;
	g.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		--x;
		--y;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}
	vector<int> dist(n, INF);
	dist[a] = 0;
	set<pair<int, int>> best;
	best.insert({ 0, a });
	while (!best.empty())
	{
		int u = best.begin()->second;
		best.erase(best.begin());
		for (auto&i : g[u])
			if (dist[u] + i.second < dist[i.first])
			{
				best.erase({ dist[i.first], i.first });
				dist[i.first] = dist[u] + i.second;
				best.insert({ dist[i.first], i.first });
			}
	}
	if (dist[b] == INF)
		cout << -1;
	else
		cout << dist[b];

	return 0;
}