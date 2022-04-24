#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

vector<char> used;

vector<int> tsort;

void DFStsort(int v)
{
	used[v] = true;
	for (auto& i : graph[v])
		if (!used[i])
			DFStsort(i);
	tsort.push_back(v);
}

int k = 0;
vector<int> comp;

void DFScomp(int v)
{
	comp[v] = k;
	for (auto& i : rgraph[v])
		if (comp[v] == -1)
			DFScomp(i);
}

vector<vector<int>> ngraph;

vector<int> leaves;

int DFSleaves(int v)
{
	used[v] = true;
	if (ngraph[v].size() == 0) return 1;
	int res = 0;
	for (auto& i : ngraph[v])
		if (used[i])
			res += DFSleaves(i);
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	graph.resize(n); rgraph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	used.assign(n, false);
	tsort.reserve(n);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			DFStsort(i);
	reverse(tsort.begin(), tsort.end());
	comp.resize(n, -1);
	for (int i = 0; i < n; ++i)
		if (comp[i] == -1)
			DFScomp(i), ++k;
	ngraph.resize(k);
	for (int i = 0; i < n; ++i)
		for (auto& j : graph[i])
			ngraph[comp[i]].push_back(comp[j]);
	for (auto& i : ngraph)
	{
		sort(i.begin(), i.end());
	}

	return 0;
}