#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

vector<int> d0, d;

void DFS(int v, int p = -1)
{
	d0[v] = 0; d[v] = 0;
	for (auto&i: graph[v])
		if (i != p)
		{
			DFS(i, v);
			d0[v] += d[i];
			d[v] = max(d[v], -d[i] + d0[i] + 1);
		}
	d[v] += d0[v];
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
	d0.resize(n); d.resize(n);
	DFS(0);
	cout << d[0] << '\n';

	return 0;
}