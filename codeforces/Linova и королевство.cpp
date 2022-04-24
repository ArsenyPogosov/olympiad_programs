#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, k;
vector<vector<int>> graph;
vector<int> psize, dist;
vector<bool> ind;

void DFSpsize(int v = 0, int p = -1, int d = 0)
{
	psize[v] = 1;
	dist[v] = d;
	for (auto&i: graph[v])
		if (i != p)
		{
			DFSpsize(i, v, d + 1);
			psize[v] += psize[i];
		}
}

long long res(int v = 0, int p = -1, int d = 0)
{
	long long ress = 0;
	if (ind[v]) ress += (long long)(d);
	if (!ind[v]) ++d;
	for (auto& i : graph[v])
		if (i != p)
			ress += res(i, v, d);
	return ress;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k; graph.resize(n); psize.resize(n); dist.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFSpsize();
	vector<int> order(n); iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) 
	{ 
		return dist[a] - psize[a] + 1 > dist[b] - psize[b] + 1;
	});
	ind.resize(n, false);
	for (int i = 0; i < k; ++i) ind[order[i]] = true;
	cout << res();

	return 0;
}