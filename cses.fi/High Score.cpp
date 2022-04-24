#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

long long n, m;
vector<vector<pair<long long, long long>>> graph;
vector<char> used;

void DFS(long long v)
{
	used[v] = true;
	for (auto&i: graph[v])
		if (!used[i.first])
		{
			DFS(i.first);
			if (used[n - 1]) return;
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	graph.resize(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c;
		graph[a - 1].emplace_back(b - 1, c);
	}
	vector<long long> d(n, -INF), p(n, -1); d[0] = 0;
	long long flag, count = 0;
	do
	{
		flag = -1;
		for (long long i = 0; i < n; ++i)
			for (auto& j : graph[i])
				if (d[j.first] < d[i] + j.second && d[i] != -INF)
				{
					d[j.first] = d[i] + j.second;
					if (d[j.first] > 1e13)
					{
						cout << -1 << '\n';
						return 0;
					}
					p[j.first] = i;
					flag = j.first;
				}
		++count;
	} while (flag != -1 && count < n);

	if (count < n || flag == -1)
	{
		cout << d[n - 1] << '\n';
		return 0;
	}

	long long v = flag;
	for (long long i = 0; i < n; ++i) v = p[v];
	used.resize(n);
	DFS(v);
	if (!used[n - 1])
		cout << d[n - 1] << '\n';
	else
		cout << -1 << '\n';

	return 0;
}