#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

vector<char> used;

int DFS(int v)
{
	used[v] = true;

	int res = 1;
	for (auto& i : graph[v])
		if (!used[i])
			res += DFS(i);

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin >> n >> m; graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	used.resize(n);
	bitset<100001> res; res[100000] = 1;
	for (int i = 0; i < n; ++i)
		if (!used[i])
		{
			int k = DFS(i);
			res |= (res >> k);
		}
	cout << res.to_string().substr(1, n) << '\n';
	return 0;
}