#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const long long INF = 10000000000000000;

int main()
{
	long long n, m, a, b;
	cin >> n >> m;
	vector<list<pair<long long, long long>>> g;
	list<pair<long long, long long>> r;
	g.resize(n);
	for (long long i = 0; i < m; ++i)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		--x;
		--y;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
		r.push_back({ x, y });
		r.push_back({ y, x });
	}
	cin >> a >> b;
	--a;
	--b;
	vector<long long> dist(n, INF), p(n, -1);
	dist[a] = 0;
	set<pair<long long, long long>> best;
	best.insert({ 0, a });
	while (!best.empty())
	{
		long long u = best.begin()->second;
		best.erase(best.begin());
		for (auto&i : g[u])
			if (dist[u] + i.second < dist[i.first])
			{
				best.erase({ dist[i.first], i.first });
				dist[i.first] = dist[u] + i.second;
				p[i.first] = u;
				best.insert({ dist[i.first], i.first });
			}
	}
	if (dist[b] == INF)
		cout << -1;
	else
	{
		int x = r.front().first, y = r.front().second;
		for (auto& i : r)
			if (dist[x] + )
	}

	return 0;
}