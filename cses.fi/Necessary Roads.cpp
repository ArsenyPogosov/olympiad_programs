#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;

int t = 0;
vector<int> tin;
void dfstin(int v)
{
	if (tin[v] != -1) return;
	tin[v] = t++;

	for (auto& i : graph[v])
		dfstin(i);
}

vector<int> tup;
vector<pair<int, int>> res;
void dfstup(int v, int p = -1)
{
	tup[v] = tin[v];

	for (auto& i : graph[v])
		if (i != p)
		{
			if (tup[i] == -1)
			{
				dfstup(i, v); tup[v] = min(tup[v], tup[i]);
				if (tup[i] > tin[v])
					res.emplace_back(min(i, v), max(i, v));
			}
			else
				tup[v] = min(tup[v], tin[i]);
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	tin.resize(n, -1);
	dfstin(0);

	tup.resize(n, -1);
	dfstup(0);

	cout << res.size() << '\n';
	for (auto& i : res)
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return 0;
}