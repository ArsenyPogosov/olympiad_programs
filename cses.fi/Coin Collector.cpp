#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n, m;
vector<long long> k;
vector<vector<long long>> graph, rgraph;

vector<long long> order;
vector<char> used;
void oDFS(long long v)
{
	used[v] = true;
	for (auto& i : graph[v])
		if (!used[i])
			oDFS(i);
	order.push_back(v);
}

long long c = 0;
vector<long long> color;
long long cDFS(long long v, long long t = c++)
{
	long long res = k[v];
	color[v] = t;
	for (auto& i : rgraph[v])
		if (color[i] == -1)
			res += cDFS(i, t);
	return res;
}

vector<long long> K;
vector<set<long long>> GRAPH;

vector<long long> d;
long long dDFS(long long v)
{
	d[v] = K[v];
	for (auto& i : GRAPH[v])
	{
		if (d[i] == -1) dDFS(i);
		d[v] = max(d[i] + K[v], d[v]);
	}
	return d[v];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	k.resize(n); graph.resize(n); rgraph.resize(n);
	order.resize(n); color.resize(n, -1); used.resize(n);
	for (auto& i : k) cin >> i;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	for (long long i = 0; i < n; ++i)
		if (!used[i])
			oDFS(i);
	reverse(order.begin(), order.end());
	for (auto& i : order)
		if (color[i] == -1)
			K.push_back(cDFS(i));
	GRAPH.resize(c);
	for (long long i = 0; i < n; ++i)
		for (auto& j : graph[i])
			if (color[i] != color[j])
				GRAPH[color[i]].insert(color[j]);
	d.resize(c, -1);
	long long mx = -1;
	for (long long i = 0; i < c; ++i)
		if (d[i] == -1)
			mx = max(mx, dDFS(i));
	cout << mx << '\n';

	return 0;
}