#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;

int k;
deque<int> path;
vector<int> dup, pos;

vector<char> used;

bool findPath(int v, int b)
{
	path.push_back(v); used[v] = true;
	if (v == b) return true;

	for (auto& i : graph[v])
		if (!used[i])
			if (findPath(i, b))
				return true;

	path.pop_back();
	return false;
}

void DFS(int v, int c)
{
	used[v] = true;
	for (auto& i : graph[v])
		if (!used[i])
		{
			if (pos[i] == -1)
				DFS(i, c);
			else
				dup[pos[i]] = min(dup[pos[i]], c);
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}

	used.assign(n, false);
	findPath(0, n - 1);
	k = path.size();
	dup.resize(k); iota(dup.begin(), dup.end(), 0);
	pos.resize(n, -1);
	for (int i = 0; i < k; ++i) pos[path[i]] = i;

	used.assign(n, false);
	for (int i = 0; i < k; ++i)
		DFS(path[i], i);

	int up = n;
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