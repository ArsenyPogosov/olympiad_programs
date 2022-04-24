#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;

vector<int> used, cycle;

void dfs(int v)
{
	used[v] = true;
	cycle.push_back(v);

	for (auto& i : graph[v])
		if (!used[i])
			dfs(i);
}

int main()
{
	cin >> n;
	graph.resize(n * 2);
	vector<vector<int>> l(n), r(n);

	for (int i = 0; i < n * 2; ++i)
	{
		int a, b; cin >> a >> b;
		l[a - 1].push_back(i);
		r[b - 1].push_back(i);
	}

	for (auto& i : l)
		graph[i[0]].push_back(i[1]),
		graph[i[1]].push_back(i[0]);
	for (auto& i : r)
		graph[i[0]].push_back(i[1]),
		graph[i[1]].push_back(i[0]);

	used.resize(n * 2);

	vector<int> res;
	for (int i = 0; i < n * 2; ++i)
		if (!used[i])
		{
			dfs(i);
			if (cycle.size() % 2)
			{
				cout << "NO\n";
				return 0;
			}
			for (int i = 0; i < cycle.size(); i += 2)
				res.push_back(cycle[i]);
			cycle.clear();
		}

	cout << "YES\n";
	sort(res.begin(), res.end());
	for (auto& i : res)
		cout << i + 1 << '\n';

	return 0;
}