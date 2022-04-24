#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

vector<int> sz;
void DFS(int v)
{
	sz[v] = 0;
	for (auto&i: graph[v])
		if (sz[i] == -1)
		{
			DFS(i);
			sz[v] += sz[i] + 1;
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; graph.resize(n);
	for (int i = 1; i < n; ++i)
	{
		int h; cin >> h;
		graph[h - 1].push_back(i);
	}
	sz.resize(n, -1);
	DFS(0);
	for (auto& i : sz) cout << i << ' ';
	cout << '\n';

	return 0;
}