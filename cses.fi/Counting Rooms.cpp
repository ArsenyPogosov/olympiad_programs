#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<char>> mp, used;

vector<pair<int, int>> steps(int x, int y)
{
	vector<pair<int, int>> res, moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	for (auto& mo : moves)
	{
		int nx = x + mo.first, ny = y + mo.second;
		if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < m))
			if (mp[nx][ny] == '.')
				if (!used[nx][ny])
					res.emplace_back(nx, ny);
	}

	return res;
}

void dfs(int x, int y)
{
	used[x][y] = true;
	for (auto& step : steps(x, y))
		dfs(step.first, step.second);
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	mp.resize(n, vector<char>(m));
	used.resize(n, vector<char>(m));
	for (auto& i : mp) for (auto& j : i) cin >> j;

	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mp[i][j] == '.' && !used[i][j])
			{
				++res;
				dfs(i, j);
			}
	cout << res << '\n';

	return 0;
}