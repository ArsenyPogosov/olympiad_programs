#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<vector<long long>> graph;
vector<long long> a, b, c;
vector<long long> db, dc;

void dfs1(long long v, long long p = -1)
{
	db[v] = b[v];
	dc[v] = c[v];
	for (auto&i: graph[v])
		if (i != p)
		{
			dfs1(i, v);
			db[v] += db[i];
			dc[v] += dc[i];
		}
}

long long res(long long v, long long p = -1, long long undo = 0, long long mn = 1e18)
{
	mn = min(mn, a[v]);
	long long x = max(0ll, b[v] - c[v]);
	for (auto& i : graph[v])
		if (i != p)
			if (db[i] > dc[i])
				x += db[i] - dc[i];
	x -= undo;
	long long ans = x * mn * 2;
	for (auto& i : graph[v])
		if (i != p)
			ans += res(i, v, max(0ll, db[i] - dc[i]), mn);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	db.resize(n);
	dc.resize(n);
	graph.resize(n);
	for (long long i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
	for (long long i = 0; i < n - 1; ++i)
	{
		long long x, y; cin >> x >> y; --x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs1(0);
	if (db[0] != dc[0])
		cout << -1 << '\n';
	else
		cout << res(0) << '\n';

	return 0;
}