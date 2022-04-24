#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;

vector<vector<int>> gr;
vector<int> cycle, used;

int findcycle(int v, int p = -1)
{
	used[v] = true;

	int targ = -1;
	for (auto& i : gr[v])
		if (i != p)
		{
			if (used[i])
				targ = i;
			else
				targ = findcycle(i, v);

			if (targ == -2)
				return targ;

			if (targ != -1)
			{
				cycle.push_back(v);
				if (targ == v) targ = -2;

				return targ;
			}
		}

	return targ;
}

bool solve(int l, int r)
{
	int k = r - l + 1;
	gr.assign(k, {});
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j)
			if (i != j)
			{
				if (find(graph[i + l].begin(), graph[i + l].end(), j + l) != graph[i + l].end())
					gr[i].push_back(j);
			}

	cycle.clear();
	used.assign(k, 0);

	for (int i = 0; i < k; ++i)
		if (!used[i])
		{
			findcycle(i);
			if (cycle.size())
				return true;
		}

	gr.assign(k, {});
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j)
			if (i != j)
			{
				if (find(graph[i + l].begin(), graph[i + l].end(), j + l) == graph[i + l].end())
					gr[i].push_back(j);
			}

	cycle.clear();
	used.assign(k, 0);

	for (int i = 0; i < k; ++i)
		if (!used[i])
		{
			findcycle(i);
			if (cycle.size())
				return true;
		}

	return false;
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

	for (auto& i : graph)
		sort(i.begin(), i.end());

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r; --l; --r;
		r = min(r, l + 6 - 1);

		if (solve(l, r))
		{
			cout << cycle.size() << ' ';
			for (auto& i : cycle)
				cout << i + l + 1 << ' ';
			cout << '\n';
		}
		else
			cout << -1 << '\n';
	}

	return 0;
}