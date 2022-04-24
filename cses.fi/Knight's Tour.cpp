#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n = 7;

vector<pair<int, int>> adj(int a, int b)
{
	vector<pair<int, int>> res;
	vector<pair<int, int>> step{ {1, 2}, {1, -2}, {-1, -2}, {-2, 1}, {-1, 2}, {2, 1}, {2, -1},  {-2, -1} };
	for (auto& i : step)
	{
		int na = a + i.first, nb = b + i.second;
		if (0 <= na && na < n && 0 <= nb && nb < n)
			res.emplace_back(na, nb);
	}

	return res;
}

int t = 0;
vector<vector<int>> used(n, vector<int>(n));
bool DFS(int a, int b)
{
	if (t == n * n)
		return true;
	if (used[a][b])
		return false;
	used[a][b] = ++t;
	for (auto& i : adj(a, b))
		if (DFS(i.first, i.second))
			return true;

	used[a][b] = 0; --t;
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b; cin >> a >> b; 
	DFS(a - 1, b - 1);
	for (auto& i : used)
	{
		for (auto& j : i)
			cout << j << ' ';
		cout << '\n';
	}

	return 0;
}