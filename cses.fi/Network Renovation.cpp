#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

int root;
vector<int> leaves;

void DFS(int v, int p = -1)
{
	if (graph[v].size() == 1)
	{
		leaves.push_back(v);
		return;
	}
	for (auto& i : graph[v])
		if (i != p)
			DFS(i, v);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; graph.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (root = 0; graph[root].size() == 1; ++root);
	DFS(root);
	int m = leaves.size();
	if (m % 2 == 1)
	{
		leaves.push_back(leaves[0]);
		++m;
	}
	cout << m / 2 << '\n';
	for (int i = 0; i < m / 2; ++i)
		cout << leaves[i] + 1 << ' ' << leaves[m / 2 + i] + 1 << '\n';

	return 0;
}