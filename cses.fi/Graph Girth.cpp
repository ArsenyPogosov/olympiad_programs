#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int res = n + 1;
	for (int i = 0; i < n; ++i)
	{
		vector<int> dist(n, -1), p(n, -1); dist[i] = 0;
		queue<int> Q; Q.push(i);
		while (Q.size())
		{
			int v = Q.front(); Q.pop();
			for (auto& j : graph[v])
				if (j != p[v])
			{
				if (dist[j] != -1)
					res = min(res, dist[j] + dist[v] + 1);
				else
				{
					dist[j] = dist[v] + 1;
					p[j] = v;
					if (dist[j] * 2 - 1 < res)
						Q.push(j);
				}
			}
		}
	}
	cout << ( res != n + 1 ? res : -1) << '\n';

	return 0;
}