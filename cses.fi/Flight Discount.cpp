#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m; cin >> n >> m;
	vector<vector<pair<long long, long long>>> graph(n), rgraph(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a].emplace_back(b, c);
		rgraph[b].emplace_back(a, c);
	}

	vector<long long> da(n, INF); da[0] = 0;
	set<pair<long long, long long>> dasort; 
	for (long long i = 0; i < n; ++i)
		dasort.emplace(da[i], i);
	for (long long t = 0; t < n; ++t)
	{
		long long v = dasort.begin()->second; dasort.erase(dasort.begin());
		for (auto&i: graph[v])
			if (da[i.first] > da[v] + i.second)
			{
				dasort.erase(make_pair(da[i.first], i.first));
				da[i.first] = da[v] + i.second;
				dasort.emplace(da[i.first], i.first);
			}
	}
	vector<long long> db(n, INF); db[n - 1] = 0;
	set<pair<long long, long long>> dbsort;
	for (long long i = 0; i < n; ++i)
		dbsort.emplace(db[i], i);
	for (long long t = 0; t < n; ++t)
	{
		long long v = dbsort.begin()->second; dbsort.erase(dbsort.begin());
		for (auto& i : rgraph[v])
			if (db[i.first] > db[v] + i.second)
			{
				dbsort.erase(make_pair(db[i.first], i.first));
				db[i.first] = db[v] + i.second;
				dbsort.emplace(db[i.first], i.first);
			}
	}

	long long res = INF;
	for (long long i = 0; i < n; ++i)
		for (auto& j : graph[i])
			res = min(res, da[i] + j.second / 2 + db[j.first]);
	cout << res << '\n';

	return 0;
}