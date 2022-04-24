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
	vector<int> p(n);
	for (auto& i : p) cin >> i;

	for (int i = 0; i < n; ++i)
	{
		set<int> prev;
		for (auto& j : graph[i])
		{
			if (p[j] < p[i])
				prev.insert(p[j]);
			if (p[j] == p[i])
			{
				cout << -1;
				return 0;
			}
		}
		if (prev.size() != p[i] - 1)
		{
			cout << -1;
			return 0;
		}
	}
	set<pair<int, int>> order;
	for (int i = 0; i < n; ++i)
		order.emplace(p[i], i);
	for (auto& i : order) cout << i.second + 1 << ' '; cout << '\n';

	return 0;
}