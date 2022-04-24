#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int n;
vector<vector<int>> ngraph;

vector<int> used;

int k;
vector<int> path, pos;

bool findpath(int v, int e)
{
	path.push_back(v); used[v] = true;
	if (v == e) return true;

	for (auto& i : ngraph[v])
		if (!used[i])
			if (findpath(i, e))
				return true;

	path.pop_back();
	return false;
}

vector<int> dup;

void DFS(int v, int c)
{
	used[v] = true;
	for (auto&i: ngraph[v])
		if (!used[i])
		{
			if (pos[i] == -1)
				DFS(i, c);
			else if (pos[i] > c + 1)
				dup[pos[i]] = min(dup[pos[i]], c);
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		graph[a - 1].emplace_back(b - 1, c);
	}

	vector<long long> d(n, INF); d[0] = 0;
	set<pair<long long, int>> dist;
	for (int i = 0; i < n; ++i) dist.emplace(d[i], i);
	for (int i = 0; i < n; ++i)
	{
		int v = dist.begin()->second; dist.erase(dist.begin());
		if (d[v] == INF) break;
		for (auto&j: graph[v])
			if (d[j.first] > d[v] + j.second)
			{
				dist.erase({ d[j.first], j.first });
				d[j.first] = d[v] + j.second;
				dist.emplace(d[j.first], j.first);
			}
	}

	ngraph.resize(n);
	for (int i = 0; i < n; ++i)
		for (auto& j : graph[i])
			if (d[i] + j.second == d[j.first])
				ngraph[i].push_back(j.first);

	used.assign(n, false);
	path.reserve(n); pos.resize(n, -1);
	findpath(0, n - 1); k = path.size();
	for (int i = 0; i < k; ++i) pos[path[i]] = i;

	used.assign(n, false);
	dup.resize(k); iota(dup.begin(), dup.end(), 0);
	for (int i = 0; i < k; ++i)
		DFS(path[i], i);
	
	int up = k;
	vector<int> res;
	for (int i = k - 1; i >= 0; --i)
	{
		if (up >= i) res.push_back(path[i]);
		up = min(up, dup[i]);
	}
	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto& i : res) cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}