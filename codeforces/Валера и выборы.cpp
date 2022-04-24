#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<int> res;

int dfs(int v = 0, int p = -1, int b = 0)
{
	int g = 0;
	for (auto&i: graph[v])
		if (i.first != p)
			g |= dfs(i.first, v, i.second);
	if (!g && b)
	{
		res.push_back(v + 1);
		g = 1;
	}

	return g;
}

int main()
{
	cin >> n; graph.resize(n); res.reserve(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b; --c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	dfs();
	cout << res.size() << '\n';
	for (auto& i : res) cout << i << ' ';
	cout << '\n';

	return 0;
}