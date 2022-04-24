#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

auto hasher = hash<string>();

long long getroothash(vector<vector<int>>& graph, int v, int p = -1)
{
	vector<long long> tohash; tohash.reserve(graph[v].size() - (p != -1));
	for (auto& i : graph[v])
		if (i != p)
			tohash.push_back(getroothash(graph, i, v));
	string res = "1";
	sort(tohash.begin(), tohash.end());
	for (auto& i : tohash)
		res += to_string(i);
	return hasher(res);
}

pair<int, int> center(vector<vector<int>> graph)
{
	int n = graph.size();
	queue<int> q;
	vector<int> d;

	d.assign(n, -1);
	q.push(0); d[0] = 0;
	while (q.size())
	{
		int v = q.front(); q.pop();
		for (auto&i: graph[v])
			if (d[i] == -1)
			{
				d[i] = d[v] + 1;
				q.push(i);
			}
	}
	int a = max_element(d.begin(), d.end()) - d.begin();

	vector<int> p(n, -1);
	d.assign(n, -1);
	q.push(a); d[a] = 0;
	while (q.size())
	{
		int v = q.front(); q.pop();
		for (auto& i : graph[v])
			if (d[i] == -1)
			{
				p[i] = v;
				d[i] = d[v] + 1;
				q.push(i);
			}
	}
	int b = max_element(d.begin(), d.end()) - d.begin();

	pair<int, int> res;
	int cnt = 0;
	for (int it = b; it != -1; it = p[it], ++cnt)
	{
		if (cnt == (d[b] + 0) / 2)
			res.first = it;
		if (cnt == (d[b] + 1) / 2)
			res.second = it;
	}

	return res;
}

long long gethash(vector<vector<int>> graph)
{
	pair<int, int> c = center(graph);
	int a = getroothash(graph, c.first), b = getroothash(graph, c.second);
	return hasher(to_string(min(a, b)) + to_string(max(a, b)));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<vector<int>> graph1(n), graph2(n);
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			graph1[a].push_back(b);
			graph1[b].push_back(a);
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			graph2[a].push_back(b);
			graph2[b].push_back(a);
		}
		cout << (gethash(graph1) == gethash(graph2) ? "YES" : "NO") << '\n';
	}
}
