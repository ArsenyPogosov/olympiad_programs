#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m; cin >> n >> m;
	vector<vector<pair<long long, long long>>> graph(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a].emplace_back(b, c);
		//graph[b].emplace_back(a, c);
	}
	vector<long long> d(n, INF); d[0] = 0;
	set<pair<long long, long long>> dsort;
	for (long long i = 0; i < n; ++i)
		dsort.emplace(d[i], i);
	for (long long t = 0; t < n; ++t)
	{
		long long v = dsort.begin()->second; dsort.erase(dsort.begin());
		for (auto&i: graph[v])
			if (d[i.first] > d[v] + i.second)
			{
				dsort.erase(make_pair(d[i.first], i.first));
				d[i.first] = d[v] + i.second;
				dsort.emplace(d[i.first], i.first);
			}
	}
	for (auto& i : d) cout << i << ' ';
	cout << '\n';

	return 0;
}