#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = int(1e9) + 9;

pair<int, int> add(pair<int, int> a, pair<int, int> b)
{
	return { (a.first + b.first) % p, (a.second + b.second) % p };
}

pair<int, int> mult(pair<int, int> a, pair<int, int> b)
{
	return { (a.first * 1ll * b.second + b.first * 1ll * a.second) % p, (a.second * 1ll * b.second) % p };
}

int n, m;
vector<vector<int>> graph;
vector<int> op;

vector<pair<int, int>> res;

void DFS(int v)
{
	if (res[v] != pair<int, int>{-1, -1}) return;
	if (op[v] == 0)
	{
		res[v] = { 0, 0 };
		for (auto& j : graph[v])
		{
			DFS(j);
			res[v] = add(res[v], res[j]);
		}
	}
	if (op[v] == 1)
	{
		res[v] = { 0, 1 };
		for (auto& j : graph[v])
		{
			DFS(j);
			res[v] = mult(res[v], res[j]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int q; cin >> n >> m >> q;
	op.resize(n, -1);
	res.resize(n, { -1, -1 });
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		if (s == "+")
		{
			op[i] = 0;
			continue;
		}
		if (s == "*")
		{
			op[i] = 1;
			continue;
		}
		if (s == "x")
		{
			res[i] = { 1, 0 };
			continue;
		}
		res[i] = { 0, stoi(s) };
	}

	graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		graph[b - 1].push_back(a - 1);
	}

	DFS(0);
	for (int i = 0; i < q; ++i)
	{
		int x; cin >> x;
		cout << (res[0].first * 1ll * x + res[0].second) % p << '\n';
	}

	return 0;
}