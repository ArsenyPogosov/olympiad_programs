#include<bits/stdc++.h>
using namespace std;

int n, s;
vector<vector<int>> graph;

int t = 0;
vector<int> tin, tout;

void dfs(int v, int p = -1)
{
	tin[v] = t++;

	for (auto& i : graph[v])
		if (i != p)
			dfs(i, v);

	tout[v] = t++;
}

int main()
{
	int q; cin >> n >> q;
	graph.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		if (b == -1)
			s = a;
		else
		{
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}

	tin.resize(n); tout.resize(n);
	dfs(s);

	vector<int> res(n);
	while (q--)
	{
		int k; cin >> k;
		vector<int> stack{-1}, tek(k);
		vector<pair<int, int>> line;
		for (int i = 0; i < k; ++i)
		{
			int x; cin >> x; --x;
			line.emplace_back(tin[x], x);
			line.emplace_back(tout[x], -1);
			tek[i] = x;
		}
		sort(line.begin(), line.end());
		for (auto& i : line)
		{
			if (i.second == -1)
				stack.pop_back();
			else
			{
				res[i.second] = stack.back();
				stack.push_back(i.second);
			}
		}

		for (auto& i : tek)
			cout << i + 1 << ' ' << res[i] + 1 << '\n';
	}

	return 0;
}