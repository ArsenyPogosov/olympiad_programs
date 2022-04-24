#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> edge(m);
	vector<vector<int>> graph(n);
	vector<int> d(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> edge[i].first >> edge[i].second; --edge[i].first; --edge[i].second;
		graph[edge[i].second].push_back(i);
		++d[edge[i].first]; --d[edge[i].second];
	}
	for (int i = 1; i < n - 1; ++i)
		if (d[i] != 0)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	if (d[0] != 1 || d[n - 1] != -1)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vector<int> res, c(n); res.reserve(m + 1);
	vector<char> used(m);
	stack<int> s;
	s.push(n - 1);
	while (s.size())
	{
		int v = s.top();
		for (; c[v] < graph[v].size() && used[graph[v][c[v]]]; ++c[v]);
		if (c[v] < graph[v].size())
		{
			used[graph[v][c[v]]] = true;
			s.push(edge[graph[v][c[v]]].first + edge[graph[v][c[v]]].second - v);
		}
		else
		{
			res.push_back(v);
			s.pop();
		}
	}

	if (res.size() != m + 1)
		cout << "IMPOSSIBLE\n";
	else
		for (auto& i : res) cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}