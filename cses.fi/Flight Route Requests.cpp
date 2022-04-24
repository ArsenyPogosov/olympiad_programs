#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

vector<char> used;

vector<int> comp;

void DFScomp(int v)
{
	used[v] = true; comp.push_back(v);

	for (auto& i : graph[v])
		if (!used[i])
			DFScomp(i);
	for (auto& i : rgraph[v])
		if (!used[i])
			DFScomp(i);
}

bool DFSloop(int v)
{
	used[v] = 1;
	for (auto& i : graph[v])
	{
		if (used[i] == 1) return true;
		if (used[i] == 2) continue;
		if (DFSloop(i)) return true;
	}
	used[v] = 2;

	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; graph.resize(n); rgraph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}

	int res = 0;
	used.resize(n);
	for (int i = 0; i < n; ++i)
		if (!used[i])
		{
			comp.clear();
			DFScomp(i);
			for (auto& j : comp) used[j] = false;
			res += comp.size() - 1;
			for (auto& j : comp)
				if (DFSloop(j))
				{
					++res;
					break;
				}
			for (auto& j : comp) used[j] = true;
		}

	cout << res << '\n';

	return 0;
}