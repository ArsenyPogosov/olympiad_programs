#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

int t = 0;
vector<int> tout;
void dfs1(int v)
{
	++t;
	tout[v] = 0;
	for (auto& i : graph[v])
		if (tout[i] == -1)
			dfs1(i);
	tout[v] = t++;
}

vector<int> used;
void dfs2(int v, int k)
{
	used[v] = k;
	for (auto& i : rgraph[v])
		if (!used[i])
			dfs2(i, k);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; graph.resize(n); rgraph.resize(n); tout.resize(n, -1); used.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	int start;
	for (int i = 0; i < n; ++i)
		if (tout[i] == -1)
		{
			dfs1(i);
			start = i;
		}
	vector<int> pos(n); iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&](int a, int b) { return tout[a] > tout[b]; });
	int k = 1;
	for (auto& i : pos)
		if (!used[i])
			dfs2(i, k++);
	cout << k - 1 << '\n';
	for (auto& i : used) cout << i << ' '; cout << '\n';

	return 0;
}