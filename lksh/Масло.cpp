#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int INF = 10000000;

vector<int> used, dist;

int main()
{
	long long n, m;
	cin >> n >> m;
	vector<list<pair<long long, long long>>> g(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}
	used.resize(n, false);
	dist.resize(n, INF);
	set<pair<int, int>> q;
	dist[0] = 0;
	q.insert({ 0, 0 });
	int maxx = 0;
	while (!q.empty())
	{
		int v = q.begin()->second;
		q.erase(q.begin());
		used[v] = true;
		maxx = max(maxx, dist[v]);
		for (auto&i : g[v])
			if (!used[i.first])
				if (dist[i.first] > i.second)
				{
					q.erase({ dist[i.first], i.first });
					dist[i.first] = i.second;
					q.insert({ dist[i.first], i.first });
				}
	}
	cout << maxx;

	return 0;
}