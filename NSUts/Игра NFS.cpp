#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

long long GCD(long long a, long long b)
{
	return (b > 0 ? GCD(b, a % b) : a);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long U, V; cin >> U >> V;
	long long n, m; cin >> n >> m;
	vector<vector<pair<long long, long long>>> graph(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	for (auto& i : graph) sort(i.begin(), i.end());
	long long t; cin >> t;
	long long start, res2 = 0; cin >> start; --t; --start;
	while (t--)
	{
		long long nxt; cin >> nxt; --nxt;
		res2 += lower_bound(graph[start].begin(), graph[start].end(), pair<long long, long long>{ nxt, 0 })->second;
		start = nxt;
	}
	res2 *= U;
	vector<long long> dist(n, INF); dist[0] = 0;
	set<pair<long long, long long>> mdist;
	for (long long i = 0; i < n; ++i) mdist.emplace(dist[i], i);
	while (mdist.size())
	{
		long long v = mdist.begin()->second; mdist.erase(mdist.begin());
		if (dist[v] == INF) break;
		for (auto& i : graph[v])
		{
			long long u = i.first, c = i.second;
			if (dist[u] > dist[v] + c)
			{
				mdist.erase({dist[u], u });
				dist[u] = dist[v] + c;
				mdist.emplace(dist[u], u);
			}
		}
	}
	long long res1 = dist[n - 1] * V, d = GCD(res1, res2);
	res1 /= d;
	res2 /= d;
	cout << (res1 < res2 ? "Epic Win!" : "Epic Fail!") << '\n' << res1 << '/' << res2 << '\n';

	return 0;
}