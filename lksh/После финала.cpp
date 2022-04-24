#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<pair<long long, long long>>> g;

const long long INF = 1000000000000000000;

int main()
{
	long long n, m;
	cin >> n >> m;
	g.resize(n);
	for (long long i = 0; i < m; ++i)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		--x;
		--y;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}
	vector<long long> dist(n, INF), len(n);
	dist[0] = 0;
	set<pair<long long, long long>> best;
	best.insert({ 0, 0 });
	while (!best.empty())
	{
		long long u = best.begin()->second;
		best.erase(best.begin());
		for (auto&i : g[u])
		{
			int v = i.first, w = i.second;
			if ((dist[u] + w < dist[v]) || ((dist[u] + w <= dist[v]) && (len[v] < len[u] + 1)))
			{
				best.erase({ dist[v], v });
				dist[v] = dist[u] + i.second;
				len[v] = len[u] + 1;
				best.insert({ dist[v], v });
			}
		}
	}
	if (dist[n - 1] == INF)
		cout << -1;
	else
		cout << dist[n - 1] << ' ' << len[n - 1];

	return 0;
}