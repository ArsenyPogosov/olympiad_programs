#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph(n);
vector<bitset<5 * 10000>> anc;

void dfs(int v)
{
	if (anc[v][v]) return;

	anc[v][v] = 1;
	for (auto& i : graph[v])
	{
		dfs(i);
		anc[v] |= anc[i];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}

	anc.resize(n);
	for (int i = 0; i < n; ++i)
		dfs(i), cout << anc[i].count() << ' ';
	cout << '\n';

	return 0;
}