#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<char>> table;
vector<vector<int>> t;

vector<pair<int, int>> adj(int x, int y)
{
	vector<pair<int, int>> res, step{ {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
	for (auto& i : step)
	{
		int nx = x + i.first, ny = y + i.second;
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
			res.emplace_back(nx, ny);
	}

	return res;
}

queue<pair<int, int>> megaq;

void BFS(int x, int y)
{
	int c = 1 - table[x][y], tm = t[x][y] + 1;
	queue<pair<int, int>> q; q.emplace(x, y);
	while (q.size())
	{
		x = q.front().first; y = q.front().second; q.pop();
		for (auto& i : adj(x, y))
		{
			int ix = i.first, iy = i.second;
			if (table[ix][iy] == c && t[ix][iy] == -1)
			{
				t[ix][iy] = tm;
				q.emplace(ix, iy);
				megaq.emplace(ix, iy);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ttt; cin >> n >> m >> ttt;
	table.assign(n, vector<char>(m));
	t.assign(n, vector<int>(m, -1));
	for (auto& i : table)
		for (auto& j : i)
			cin >> j, j -= '0';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (t[i][j] == -1)
			{
				bool flag = false;
				for (auto& k : adj(i, j))
					if (table[k.first][k.second] == table[i][j])
						flag = true;
				if (flag)
				{
					t[i][j] = -1;
					table[i][j] = 1 - table[i][j];
					BFS(i, j);
					t[i][j] = 0;
					table[i][j] = 1 - table[i][j];
					megaq.emplace(i, j);
				}
			}
	while (megaq.size())
	{
		int x = megaq.front().first, y = megaq.front().second; megaq.pop();
		BFS(x, y);
	}

	while (ttt--)
	{
		int x, y; long long p; cin >> x >> y >> p; --x; --y;
		if (t[x][y] == -1)
			cout << 0 + table[x][y] << '\n';
		else
			cout << (max(0ll, p - t[x][y]) + table[x][y]) % 2 << '\n';
	}

	return 0;
}