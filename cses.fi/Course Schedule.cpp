#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<char> used;
vector<int> res;

bool DFS(int v)
{
	used[v] = 1;
	for (auto& u : graph[v])
	{
		if (used[u] == 2) continue;
		if (used[u] == 1) return false;
		if (!DFS(u)) return false;
	}
	res.push_back(v);
	used[v] = 2;
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; graph.resize(n); res.reserve(n); used.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}
	for (int i = 0; i < n; ++i)
		if (!used[i]) 
			if (!DFS(i))
			{
				cout << "IMPOSSIBLE\n";
				return 0;
			}
	reverse(res.begin(), res.end());
	for (auto& i : res) cout << i + 1 << ' '; cout << '\n';

	return 0;
}