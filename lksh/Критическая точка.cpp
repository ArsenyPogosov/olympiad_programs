#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> d, up;

int vmx = -1, mx = -1;
void DFS(int v, int p = -1)
{
	d[v] = (p != -1 ? d[p] + 1 : 0);
	up[v] = d[v];
	int res = (p != -1);
	for (auto&u: graph[v])
		if (u != p)
		{
			if (d[u] == -1)
			{
				DFS(u, v);
				up[v] = min(up[v], up[u]);
				if (up[u] >= d[v]) ++res;
			}
			else
				up[v] = min(up[v], d[u]);
		}

	if (res > mx || (res == mx && v < vmx))
	{
		mx = res;
		vmx = v;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	graph.resize(n); d.resize(n, -1); up.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
		if (d[i] == -1) DFS(i);
	cout << vmx + 1 << '\n';

	return 0;
}