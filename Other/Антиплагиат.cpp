#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> c;
vector<vector<int>> graph;

int res = 0;
unordered_map<int, int> used;

pair<int, int> dfs(int v, int p = -1)
{
	int cnt = 0;
	string s = to_string(c[v]+123) + ',' + to_string(graph[v].size() - (p != -1) + 3424563);
	vector<int> ch;
	for (auto&i: graph[v])
		if (i != p)
		{
			pair<int, int> curr = dfs(i, v);
			cnt += curr.first;
			ch.push_back(curr.second + 23423);
		}
	sort(ch.begin(), ch.end());
	for (auto& i : ch)
		s += ',' + to_string(i);

	int h = hash<string>()(s);

	res += used[h]++;

	return { cnt, h };
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(0));

	cin >> n;
	c.resize(n);
	graph.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (auto& i : c) cin >> i;

	dfs(0);

	cout << res << '\n';

	return 0;
}