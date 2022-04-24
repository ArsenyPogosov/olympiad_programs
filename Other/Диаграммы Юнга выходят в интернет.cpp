#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

vector<int> tsort;
vector<char> used;
void dfs1(int v)
{
	if (used[v]) return;
	used[v] = true;

	for (auto& i : graph[v])
		dfs1(i);

	tsort.push_back(v);
}

int c;
vector<int> color;

void dfs2(int v)
{
	if (color[v] != -1) return;
	color[v] = c;

	for (auto& i : rgraph[v])
		dfs2(i);

}

vector<vector<int>> graph2, rgraph2;

vector<char> used1;
void dfs3(int v)
{
	if (used1[v]) return;
	used1[v] = true;

	for (auto& i : graph2[v])
		dfs3(i);
}

vector<char> used2;
void dfs4(int v)
{
	if (used2[v]) return;
	used2[v] = true;

	for (auto& i : rgraph2[v])
		dfs4(i);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		graph.assign(n, {});
		rgraph.assign(n, {});

		for (int i = 0; i < m; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			graph[a].push_back(b);
			rgraph[b].push_back(a);
		}

		tsort.clear();
		used.assign(n, false);
		for (int i = 0; i < n; ++i)
			dfs1(i);
		reverse(tsort.begin(), tsort.end());

		c = 0;
		color.assign(n, -1);
		for (auto& i : tsort)
			if (color[i] == -1)
			{
				dfs2(i);
				++c;
			}

		vector<char> weakness(c, 2);
		for (auto& i : color)
			weakness[i] = max((char)1, weakness[i]) - 1;

		graph2.assign(c, {});
		rgraph2.assign(c, {});
		for (int i = 0; i < n; ++i)
			for (auto& j : graph[i])
				if (color[i] != color[j])
				{
					graph2[color[i]].push_back(color[j]);
					rgraph2[color[j]].push_back(color[i]);
				}
				else
					weakness[color[i]] = false;

		used1.assign(c, false);
		dfs3(color[0]);
		used2.assign(c, false);
		dfs4(color[n - 1]);

		for (int i = 0; i < c; ++i)
			weakness[i] &= used1[i] & used2[i];

		vector<int> bracket(c);
		for (int i = 0; i < c; ++i)
			if (used1[i])
				for (auto& j : graph2[i])
					if (used2[j])
					{
						++bracket[i + 1];
						--bracket[j];
					}
		int cnt = 0;
		for (int i = 0; i < c; ++i)
		{
			cnt += bracket[i];
			if (cnt > 0)
				weakness[i] = false;
		}

		vector<int> example(c);
		for (int i = 0; i < n; ++i)
			example[color[i]] = i;

		vector<int> res;
		for (int i = 0; i < c; ++i)
			if (weakness[i])
				res.push_back(example[i]);

		cout << res.size() << '\n';
		for (auto& i : res)
			cout << i + 1 << ' ';
		cout << '\n';
	}

	return 0;
}