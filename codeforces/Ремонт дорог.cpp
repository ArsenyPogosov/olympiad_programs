#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<int> res;

void dfs(int v = 0, int p = -1)
{
	res[v] = graph[v].size() - 1 + (v == 0);
	for (auto& i : graph[v])
		if (i.first != p)
		{
			dfs(i.first, v);
			res[v] = max(res[v], res[i.first] + (res[i.first] == graph[i.first].size() - 1));
		}
}

vector<int> dd;
vector<int> ch;
void step(int v, int p, int cu)
{
	if (res[v] < 0) return;
	--res[v];
	if (dd[v] < graph[v].size() && graph[v][dd[v]].first == p) ++dd[v];
	for (int i = 0; i < graph[v].size(); ++i)
		if (graph[v][i].first != p)
		{
			if (cu && i == dd[v])
			{
				ch.push_back(graph[v][i].second + 1);
				step(graph[v][i].first, v, 0);
			}
			else
			{
				step(graph[v][i].first, v, 1);
			}
		}
	if (cu) ++dd[v];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	graph.resize(n); res.resize(n); dd.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back({ b, i });
		graph[b].push_back({ a, i });
	}
	dfs();
	cout << res[0] << '\n';
	while(res[0])
	{
		step(0, -1, 1);
		cout << ch.size();
		for (auto& i : ch) cout << ' ' << i;
		cout << '\n';
		ch.clear();
	}

	return 0;
}