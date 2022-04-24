#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<vector<int>> graph;
vector<char> used;

void DFS(int v)
{
	used[v] = true;
	for (auto& i : graph[v])
		if (!used[i])
			DFS(i);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	graph.resize(n); used.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<pair<int, int>> res;
	DFS(0);
	for (int i = 1; i < n; ++i)
		if (!used[i])
		{
			res.push_back({ 1, i + 1 });
			DFS(i);
		}
	cout << res.size() << '\n';
	for (auto& i : res)
		cout << i.first << ' ' << i.second << '\n';

	return 0;
}