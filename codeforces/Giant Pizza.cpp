#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

int T = 0;
vector<int> p, used;

bool DFS(int v)
{
	if (used[v] == T) return false; used[v] = T;
	for (auto&i: graph[v])
		if (p[i] == -1 || DFS(p[i]))
		{
			p[i] = v;
			return true;
		}
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin >> m >> n; graph.resize(n); p.resize(n); used.resize(n, -1);
	for (int i = 0; i < m; ++i)
	{

	}

	return 0;
}