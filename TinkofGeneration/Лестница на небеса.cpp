#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> graph;

int dist(int a, int b)
{
	if (a == b) return 0;

	vector<int> dist(n, INF); dist[a] = 0;
	queue<int> q; q.push(a);
	while (q.size() && dist[b] == INF)
	{
		int v = q.front(); q.pop();

		for (auto&i: graph[v])
			if (dist[i] == INF)
			{
				dist[i] = dist[v] + 1;
				q.push(i);
			}
	}

	return dist[b] - 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int k, q; cin >> n >> k >> q;

	vector<int> a(n);
	for (auto& i : a) cin >> i;

	graph.resize(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
			if (a[j] >= a[i])
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
				break;
			}

		for (int j = i + 1; j < n; ++j)
			if (a[j] >= a[i])
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
				break;
			}
	}

	while (q--)
	{
		int a, b; cin >> a >> b; --a; --b;
		cout << dist(a, b) << '\n';
	}

	return 0;
}