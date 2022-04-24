#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int n, m;
vector<vector<int>> graph;

vector<int> used;
int dfs(int v)
{
	if (used[v]) return 1;
	used[v] = 1;

	int res = -1;
	for (auto& i : graph[v])
		res += dfs(i);

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int cnt = 0;
	used.resize(n);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			cnt += (dfs(i) + 1) / 2;

	int res = 1;
	for (int i = 0; i < cnt; ++i)
		res = (res << 1) % p;

	cout << res << '\n';

	return 0;
}