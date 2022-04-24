#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

vector<int> used;

vector<int> order;
void DFSorder(int v)
{
	used[v] = true;
	for (auto& i : graph[v])
		if (!used[i])
			DFSorder(i);
	order.push_back(v);
}

int c = 0;
vector<int> a;
vector<vector<int>> cgraph;

int DFScomp(int v)
{
	int res = 1;
	used[v] = c;
	for (auto& i : rgraph[v])
		if (used[i] == -1)
			res += DFScomp(i);
	return res;
}

void buildcgraph()
{
	cgraph.resize(c);
	for (int i = 0; i < n; ++i)
		for (auto& j : graph[i])
			if (used[i] != used[j])
				cgraph[used[i]].push_back(used[j]);
	for (auto& i : cgraph)
	{
		sort(i.begin(), i.end());
		i.erase(unique(i.begin(), i.end()), i.end());
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	graph.resize(n);
	rgraph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	used.assign(n, 0);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			DFSorder(i);
	reverse(order.begin(), order.end());
	used.assign(n, -1);
	for (auto& i : order)
		if (used[i] == -1)
			a.push_back(DFScomp(i)), ++c;
	buildcgraph();
	int start = used[0];
	vector<int> mxdist(c, -1);
	mxdist[start] = 0;
	for (int i = 0; i < c; ++i)
		if (mxdist[i] >= 0)
			for (auto& j : cgraph[i])
				mxdist[j] = max(mxdist[j], mxdist[i] + a[j]);
	vector<int> mxrdist(c, -1);
	mxrdist[start] = 0;
	for (int i = c - 1; i >= 0; --i)
		for (auto& j : cgraph[i])
			if (mxrdist[j] >= 0)
				mxrdist[i] = max(mxrdist[i], a[i] + mxrdist[j]);
	int res = a[start];
	for (int i = 0; i < c; ++i)
		for (auto& j : cgraph[i])
			if (mxdist[j] >= 0 && mxrdist[i] >= 0)
				res = max(res, mxdist[j] + mxrdist[i] + a[start]);
	cout << res << '\n';

	return 0;
}