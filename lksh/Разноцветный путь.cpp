#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<vector<pair<int, int>>>> graph(n);
	vector<vector<int>> d(n);
	vector<vector<bool>> was(n);
	vector<char> add(n, true); add[0] = false;
	vector<vector<int>> edge(m);
	vector<vector<int>> vc(n);
	for (auto&i: edge)
	{
		i = vector<int>(3);
		cin >> i[0] >> i[1] >> i[2]; --i[0]; --i[1]; --i[2];
		vc[i[0]].push_back(i[2]);
		vc[i[1]].push_back(i[2]);
	}
	for (int i = 0; i < n; ++i)
	{
		sort(vc[i].begin(), vc[i].end());
		vc[i].erase(unique(vc[i].begin(), vc[i].end()), vc[i].end());
		graph[i].resize(vc[i].size());
		d[i].resize(vc[i].size(), INF);
		was[i].resize(vc[i].size());
	}
	for (auto& i : edge)
	{
		int a = lower_bound(vc[i[0]].begin(), vc[i[0]].end(), i[2]) - vc[i[0]].begin();
		int b = lower_bound(vc[i[1]].begin(), vc[i[1]].end(), i[2]) - vc[i[1]].begin();
		graph[i[0]][a].emplace_back(i[1], b);
		graph[i[1]][b].emplace_back(i[0], a);
	}

	deque<pair<int, int>> Q;
	for (int i = 0; i < vc[0].size(); ++i)
	{
		Q.emplace_back(0, i);
		d[0][i] = 0;
	}
	while (Q.size())
	{
		int v = Q.front().first, c = Q.front().second; Q.pop_front();
		if (was[v][c]) continue; was[v][c] = true;
		for (auto&i: graph[v][c])
			if (d[i.first][i.second] > d[v][c])
			{
				d[i.first][i.second] = d[v][c];
				Q.push_front(i);
			}
		if (add[v])
		{
			for (int i = 0; i < vc[v].size(); ++i)
				if (d[v][i] > d[v][c] + 1)
				{
					d[v][i] = d[v][c] + 1;
					Q.emplace_back(v, i);
				}
			add[v] = false;
		}
	}
	int mn = INF;
	for (auto& i : d[n - 1])
		mn = min(mn, i);
	if (mn < INF)
		cout << mn + 1 << '\n';
	else
		cout << -1 << '\n';

	return 0;
}