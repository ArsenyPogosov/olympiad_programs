#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n; m = 61;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	vector<int> count(m);
	for (auto& i : a)
		for (int j = 0; j < m; ++j)
			if (i & (1ll << j))
				++count[j];
	for (auto&i: count)
		if (i >= 3)
		{
			cout << "3\n";
			return 0;
		}
	int it = 0;
	vector<int> con(m, -1);
	vector<set<int>> graph;
	for (auto& i : a)
	{
		bool need = false;
		for (int j = 0; j < m; ++j)
			if (i & (1ll << j))
			{
				if (!need)
				{
					need = true;
					graph.push_back({});
				}
				if (con[j] == -1)
					con[j] = it;
				else
				{
					graph[it].insert(con[j]);
					graph[con[j]].insert(it);
				}
			}
		if (need) ++it;
	}
	n = it;
	int res = 1e9;
	for (int i = 0; i < n; ++i)
	{
		vector<int> dist(n, -1);
		queue<int> q;
		q.push(i); dist[i] = 0;
		while (q.size())
		{
			int v = q.front(); q.pop();
			if (dist[v] * 2 >= res) break;
			for (auto&j: graph[v])
				if (dist[j] == -1)
				{
					dist[j] = dist[v] + 1;
					q.push(j);
				}
				else if (dist[j] >= dist[v])
					res = min(res, dist[v] + 1 + dist[j]);
		}
	}
	cout << (res < 1e9 ? res : -1) << '\n';

	return 0;
}