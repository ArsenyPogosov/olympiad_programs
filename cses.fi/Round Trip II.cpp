#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;

vector<int> cycle;
vector<char> used;
int DFS(int v)
{
	if (used[v] == 2) return -1;
	if (used[v] == 1)
	{
		cycle.push_back(v);
		return v;
	} used[v] = 1;

	for (auto& u : graph[v])
	{
		int res = DFS(u);
		if (res == -1) continue;
		used[v] = 2;
		if (res == -2) return -2;
		cycle.push_back(v);
		if (res == v) return -2;
		return res;
	}

	used[v] = 2;
	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; graph.resize(n); used.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}
	for (int i = 0; i < n; ++i)
		if (!used[i] && DFS(i) != -1)
		{
			reverse(cycle.begin(), cycle.end());
			cout << cycle.size() << '\n';
			for (auto& i : cycle) cout << i + 1 << ' ';
			cout << '\n';
			return 0;
		}
	cout << "IMPOSSIBLE\n";

	return 0;
}