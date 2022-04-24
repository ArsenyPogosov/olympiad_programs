#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;
const long long INF = 1e18 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m; cin >> n >> m;
	vector<vector<pair<long long, long long>>> graph(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a].emplace_back(b, c);
	}
	vector<long long> d(n, INF), dmin(n, INF), dmax(n, -1), dcount(n, 0);
	d[0] = 0; dmin[0] = dmax[0] = 0; dcount[0] = 1;
	set<pair<long long, long long>> dv;
	for (long long i = 0; i < n; ++i) dv.emplace(d[i], i);
	for (long long i = 0; i < n; ++i)
	{
		long long v = dv.begin()->second; dv.erase(dv.begin());
		if (d[v] >= INF) break;
		for (auto&br: graph[v])
			if (d[br.first] >= d[v] + br.second)
			{
				if (d[br.first] == d[v] + br.second)
				{
					dmin[br.first] = min(dmin[br.first], dmin[v] + 1);
					dmax[br.first] = max(dmax[br.first], dmax[v] + 1);
					dcount[br.first] += dcount[v];
					dcount[br.first] %= p;
				}
				else
				{
					dmin[br.first] = dmin[v] + 1;
					dmax[br.first] = dmax[v] + 1;
					dcount[br.first] = dcount[v];
					dcount[br.first] %= p;
					dv.erase(make_pair(d[br.first], br.first));
					d[br.first] = d[v] + br.second;
					dv.emplace(d[br.first], br.first);
				}
			}
	}
	cout << d[n - 1] << ' ' << dcount[n - 1] << ' ' << dmin[n - 1] << ' ' << dmax[n - 1] << '\n';

	return 0;
}