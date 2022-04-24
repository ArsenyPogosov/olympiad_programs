#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

vector<int> used, res, cnt;

void DFS(int v)
{
	used[v] = true;
	for (auto&i: rgraph[v])
		if (!used[i])
		{
			if (res[v] == -1)
			{
				res[i] = 1;
				DFS(i);
			}
			if (res[v] == 1)
			{
				if (!--cnt[i])
				{
					res[i] = -1;
					DFS(i);
				}
			}
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (cin >> n >> m)
	{
		graph.assign(n, {});
		rgraph.assign(n, {});
		for (int i = 0; i < m; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			graph[a].push_back(b);
			rgraph[b].push_back(a);
		}

		cnt.assign(n, 0);
		for (int i = 0; i < n; ++i)
			cnt[i] = graph[i].size();

		used.assign(n, false);
		res.assign(n, 0);
		for (int i = 0; i < n; ++i)
			if (!cnt[i])
			{
				res[i] = -1;
				DFS(i);
			}

		for (auto& i : res)
		{
			if (i == -1)
				cout << "SECOND\n";
			if (i == 0)
				cout << "DRAW\n";
			if (i == 1)
				cout << "FIRST\n";
		}
	}

	return 0;
}