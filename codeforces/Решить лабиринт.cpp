#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<char>> mp;

vector<pair<int, int>> sv(int i, int j)
{
	vector<pair<int, int>> res;
	vector<pair<int, int>> step{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	for (auto& s : step)
	{
		int ni = i - s.first, nj = j - s.second;
		if (0 <= ni && ni < n && 0 <= nj && nj < m)
			if (mp[ni][nj] != '#')
				res.push_back({ ni, nj });
	}
	return res;
}

vector<vector<char>> used;
void DFS(int i, int j)
{
	used[i][j] = true;
	for (auto& x : sv(i, j))
		if (!used[x.first][x.second])
			DFS(x.first, x.second);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m; mp.assign(n, vector<char>(m));
		bool bad = false;
		for (auto& i : mp) for (auto& j : i) cin >> j;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				if (mp[i][j] == 'B')
					for (auto& x : sv(i, j))
					{
						if (mp[x.first][x.second] == 'G')
						{
							bad = true;
							break;
						}
						if (mp[x.first][x.second] == '.')
							mp[x.first][x.second] = '#';
					}
			if (bad) break;
		}
		if (bad)
		{
			cout << "No\n";
			continue;
		}
		used.assign(n, vector<char>(m, false));
		if (mp[n - 1][m - 1] != '#')
			DFS(n - 1, m - 1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				if (mp[i][j] == 'G')
					if (!used[i][j])
					{
						bad = true;
						break;
					}
			if (bad) break;
		}
		if (bad)
		{
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}

	return 0;
}