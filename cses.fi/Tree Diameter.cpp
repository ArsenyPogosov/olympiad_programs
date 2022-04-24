#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

int res = 0;
vector<int> d;
void DFS(int v, int p = -1)
{
	d[v] = 1;
	int max1 = 0, max2 = 0;
	for (auto& i : graph[v])
		if (i != p)
		{
			DFS(i, v);
			d[v] = max(d[v], d[i] + 1);
			if (max1 < d[i])
			{
				max2 = max1;
				max1 = d[i];
			}
			else if (max2 < d[i])
				max2 = d[i];
		}
	res = max(res, max1 + 1 + max2);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; graph.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	d.resize(n);
	DFS(0);
	cout << res - 1 << '\n';

	return 0;
}