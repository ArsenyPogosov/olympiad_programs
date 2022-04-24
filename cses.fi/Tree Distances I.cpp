#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

vector<int> d, backd;
void DFS(int v, int p = -1)
{
	d[v] = 1;
	for (auto&i: graph[v])
		if (i != p)
		{
			DFS(i, v);
			d[v] = max(d[v], d[i] + 1);
		}
}

void backDFS(int v, int p = -1)
{
	if (p == -1) backd[v] = 1;
	int max1 = -1, max2 = -1;
	for (auto& i : graph[v])
		if (i != p)
		{
			if (max1 == -1 || d[max1] < d[i])
			{
				max2 = max1;
				max1 = i;
			}
			else if (max2 == -1 || d[max2] < d[i])
				max2 = i;
		}
	for (auto& i : graph[v])
		if (i != p)
		{
			backd[i] = backd[v] + 1;
			if (max1 != -1 && max1 != i)
				backd[i] = max(backd[i], 2 + d[max1]);
			if (max2 != -1 && max2 != i)
				backd[i] = max(backd[i], 2 + d[max2]);
			backDFS(i, v);
		}
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
	d.resize(n); backd.resize(n);
	DFS(0); backDFS(0);
	for (int i = 0; i < n; ++i) cout << max(d[i], backd[i]) - 1 << ' ';
	cout << '\n';

	return 0;
}