#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

vector<char> used;
vector<int> sz, parent;

void DFS(int v, int p = -1)
{
	sz[v] = 1;
	for (auto&i: graph[v])
		if (i != p && !used[i])
		{
			DFS(i, v);
			sz[v] += sz[i];
		}
}

int centroid(int v)
{
	DFS(v);
	int tek = v, pre = -1;
	while (true)
	{
		bool good = true;
		for (auto&i: graph[tek])
			if (i != pre && !used[i])
				if (sz[i] > sz[v] / 2)
				{
					good = false;
					pre = tek;
					tek = i;
					break;
				}
		if (good) return tek;
	}
}

void decompose(int v, int p = -1)
{
	v = centroid(v);
	used[v] = true;
	parent[v] = p;
	for (auto& i : graph[v])
		if (!used[i])
			decompose(i, v);
}

void decompose()
{
	used.resize(n);	sz.resize(n); parent.resize(n);
	decompose(0, -1);
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

	decompose();

	for (auto& i : parent)
		cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}