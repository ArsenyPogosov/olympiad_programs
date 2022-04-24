#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> color;

void DFS(int v, int c = 1)
{
	color[v] = c;
	for (auto& i : graph[v])
		if (!color[i])
			DFS(i, 3 - c);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	graph.resize(n);
	color.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
		if (!color[i])
			DFS(i);

	for (int i = 0; i < n; ++i)
		for (auto&j: graph[i])
			if (color[i] + color[j] != 3)
			{
				cout << "IMPOSSIBLE\n";
				return 0;
			}
	for (auto& i : color) cout << i << ' ';
	cout << '\n';

	return 0;
}