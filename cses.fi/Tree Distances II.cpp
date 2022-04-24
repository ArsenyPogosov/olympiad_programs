#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<vector<long long>> graph;

vector<long long> sz, sdown, sall;
void DFS1(long long v, long long p = -1)
{
	sz[v] = 1; sdown[v] = 0;
	for (auto&i: graph[v])
		if (i != p)
		{
			DFS1(i, v);
			sz[v] += sz[i];
			sdown[v] += sdown[i] + sz[i];
		}
}

void DFS2(long long v, long long p = -1)
{
	sall[v] += sdown[v];
	for (auto&i: graph[v])
		if (i != p)
		{
			sall[i] = (sall[v] - sdown[i] - sz[i]) + n - sz[i];
			DFS2(i, v);
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; graph.resize(n);
	for (long long i = 0; i < n - 1; ++i)
	{
		long long a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	sz.resize(n); sdown.resize(n); sall.resize(n);
	DFS1(0); DFS2(0);
	for (auto& i : sall) cout << i << ' ';
	cout << '\n';

	return 0;
}