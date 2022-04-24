#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m, k; cin >> n >> m >> k;
	vector<vector<pair<long long, long long>>> graph(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c;
		graph[a - 1].emplace_back(b - 1, c);
	}
	vector<multiset<long long>> d(n); d[0] = { 0 };
	vector<long long> tf(n, 0);
	set<pair<long long, long long>> dv{ {0, 0} };
	while (dv.size())
	{
		long long v = dv.begin()->second, td = dv.begin()->first; dv.erase(dv.begin()); 
		++tf[v]; 
		if (tf[v] < d[v].size())
		{
			auto repr = d[v].begin(); advance(repr, tf[v]);
			dv.emplace(*repr, v);
		}
		for (auto& br : graph[v])
		{
			long long u = br.first, c = br.second;
			auto it = d[u].insert(td + c);
			if (d[u].size() > k)
			{
				if (it == prev(d[u].end()))
				{
					d[u].erase(prev(d[u].end()));
					continue;
				}
				d[u].erase(prev(d[u].end()));
			}
			auto repr = d[u].begin(); advance(repr, tf[u]);
			if (it == repr)
			{
				if (next(it) != d[u].end())
					dv.erase({ *next(it), u });
				dv.emplace( *it, u );
			}
		}
	}
	for (auto& i : d[n - 1]) cout << i << ' '; cout << '\n';

	return 0;
}