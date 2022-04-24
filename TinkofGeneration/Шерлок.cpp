#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> a;

vector<pair<int, int>> adj(int x, int y)
{
	vector<pair<int, int>> res, step{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	for (auto& i : step)
	{
		int nx = x + i.first, ny = y + i.second;
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
			res.emplace_back(nx, ny);
	}

	return res;
}

vector<vector<int>> ans;
int Ans(int x, int y)
{
	if (ans[x][y]) return ans[x][y];

	ans[x][y] = 1;
	for (auto& i : adj(x, y))
	{
		int nx = i.first, ny = i.second;
		if (a[x][y] + 1 == a[nx][ny])
		{
			ans[x][y] = max(ans[x][y], 1 + Ans(nx, ny));
		}
	}

	return ans[x][y];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	a.resize(n, vector<int>(m));
	for (auto& i : a)
		for (auto& j : i)
			cin >> j;

	int res = 0;
	ans.resize(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			res = max(res, Ans(i, j));
	cout << res << '\n';

	return 0;
}