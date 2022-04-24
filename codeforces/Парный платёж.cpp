#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long k = 51;
	long long n, m; cin >> n >> m;
	vector<vector<pair<long long, long long>>> graph(n);

	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	vector<vector<long long>> dist(n, vector<long long>(k, INF));
	dist[0][0] = 0;
	set<pair<long long, pair<long long, long long>>> best;
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < k; ++j)
			best.emplace(dist[i][j], pair<long long, long long>{i, j});

	while (best.size())
	{
		long long x = best.begin()->second.first, y = best.begin()->second.second; best.erase(best.begin());
		if (dist[x][y] >= INF) break;

		for (auto& i : graph[x])
		{
			long long a = i.first, b = (y > 0 ? 0: i.second);
			long long nd = dist[x][y] + (y > 0 ? (y + i.second) * (y + i.second) : 0);
			if (dist[a][b] > nd)
			{
				best.erase({ dist[a][b], {a, b} });
				dist[a][b] = nd;
				best.insert({ dist[a][b], {a, b} });
			}
		}
	}

	for (long long i = 0; i < n; ++i)
		cout << (dist[i][0] < INF ? dist[i][0] : -1) << ' ';
	cout << '\n';

	return 0;
}