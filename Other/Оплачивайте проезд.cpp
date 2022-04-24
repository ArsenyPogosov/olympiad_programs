#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, q; cin >> n >> m >> q;

	vector<pair<int, int>> edge(m);
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> edge[i].first >> edge[i].second; --edge[i].first; --edge[i].second;
		graph[edge[i].first].push_back(i);
		graph[edge[i].second].push_back(i);
	}

	vector<int> d(n, -1);
	queue<int> que;
	d[0] = 0; que.push(0);

	while (que.size())
	{
		int v = que.front(); que.pop();

		for (auto& i : graph[v])
		{
			int u = edge[i].first ^ edge[i].second ^ v;
			if (d[u] == -1)
			{
				d[u] = d[v] + 1;
				que.push(u);
			}
		}
	}

	vector<int> dtime(m, q);
	for (int i = 0; i < q; ++i)
	{
		int h; cin >> h; --h;
		dtime[h] = i;
	}

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b) { return d[a] < d[b]; });

	vector<int> dp(n, -1); dp[0] = q;
	for (auto&v: ord)
	{
		for (auto& i : graph[v])
		{
			int u = edge[i].first ^ edge[i].second ^ v;
			if (d[v] == d[u] + 1)
				dp[v] = max(dp[v], min(dtime[i], dp[u]));
		}
	}

	vector<int> res(q + 1);
	for (auto& i : dp)
		if (i != -1)
			++res[i];
	for (int i = 1; i < q; ++i)
		res[i] += res[i - 1];

	for (int i = 0; i < q; ++i)
		cout << res[i] << '\n';

	return 0;
}