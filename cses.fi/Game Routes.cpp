#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int n, m;
vector<vector<int>> graph;
vector<int> k;

vector<char> used;
void DFS(int v)
{
	used[v] = true;
	for (auto& u : graph[v])
	{
		++k[u];
		if (!used[u]) DFS(u);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; graph.resize(n); k.resize(n); used.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
	}
	DFS(0);

	vector<int> d(n, 0); d[0] = 1;
	queue<int> znode; znode.push(0);
	while (znode.size())
	{
		for (auto& i : graph[znode.front()])
		{
			--k[i];
			if (k[i] == 0) znode.push(i);
			d[i] += d[znode.front()];
			d[i] %= p;
		}
		znode.pop();
	}
	cout << d[n - 1] << '\n';

	return 0;
}