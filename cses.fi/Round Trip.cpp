#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<char> used;
vector<int> res;

int DFS(int v, int p = -1)
{
	used[v] = true;
	for (auto& i : graph[v])
		if (i != p)
		{
			if (!used[i])
			{
				int ans = DFS(i, v);
				if (ans == -2) return -2;
				if (ans == -1) continue;
				res.push_back(v);
				if (ans == v) return -2;
				return ans;
			}
			if (used[i])
			{
				res.push_back(v);
				return i;
			}
		}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	graph.resize(n);
	used.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
		if (!used[i])
			if (DFS(i) == -2)
				break;

	if (!res.size())
		cout << "IMPOSSIBLE\n";
	else
	{
		reverse(res.begin(), res.end());
		cout << res.size() + 1 << '\n';
		for (auto& i : res) cout << i + 1 << ' ';
		cout << res[0] + 1 << '\n';
	}

	return 0;
}