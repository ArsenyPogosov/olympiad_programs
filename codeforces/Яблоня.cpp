#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;
vector<long long> a, part;

long long GCD(long long a, long long b)
{
	return (a == 0 ? b : GCD(b % a, a));
}

long long LCA(long long a, long long b)
{
	long long g = GCD(a, b);
	a /= g;
	if (a > (long long)(1e13) / b)
		return -1;
	return a * b;
}

int dfs(int v = 0, int p = -1)
{
	if (graph[v].size() == 1 && p != -1) 
		return 0;
	if (part[v] > (long long)(1e13) / (graph[v].size() - 1 + (p == -1)))
		return 1;
	long long nw = part[v] * (graph[v].size() - 1 + (p == -1));
	for (auto& i : graph[v])
		if (i != p)
		{
			part[i] = nw;
			if (dfs(i, v))
				return 1;
		}

	return 0;
}

int main()
{
	cin >> n; graph.resize(n); a.resize(n); part.resize(n);
	for (auto& i : a) cin >> i; a[0] = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	long long s = 0;
	for (auto& i : a) s += i;
	part[0] = 1;
	if (dfs())
	{
		cout << s << '\n';
		return 0;
	}
	long long minroot = 1;
	for (int i = 1; i < n; ++i)
		if (graph[i].size() == 1)
		{
			minroot = LCA(minroot, part[i]);
			if (minroot == -1)
			{
				cout << s << '\n';
				return 0;
			}
		}
	long long maxk = (long long)(1e13) / minroot;
	for (int i = 1; i < n; ++i)
		if (graph[i].size() == 1)
			maxk = min(maxk, a[i] / (minroot / part[i]));
	long long res = 0;
	for (int i = 1; i < n; ++i)
		if (graph[i].size() == 1)
			res += a[i] - (minroot / part[i]) * maxk;
	cout << res << '\n';

	return 0;
}