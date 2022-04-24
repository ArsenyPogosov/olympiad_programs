#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> color;

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

vector<vector<vector<char>>> used;

int dfs(int x, int y, int nc)
{
	if (used[x][y][nc]) return 0;
	used[x][y][nc] = true;

	int res = 1;
	for (auto& i : adj(x, y))
	{
		int nx = i.first, ny = i.second;
		if (color[nx][ny] == color[x][y])
			res += dfs(nx, ny, nc);
		if (color[nx][ny] == nc)
			res += dfs(nx, ny, color[x][y]);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	color.resize(n, vector<int>(m));
	vector<pair<int, int*>> srt(n * m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> srt[i * m + j].first;
			srt[i * m + j].second = &(color[i][j]);
		}
	sort(srt.begin(), srt.end());
	int was = -1, t = 0;
	for (auto& i : srt)
	{
		if (was < i.first)
		{
			was = i.first;
			++t;
		}
		*i.second = t - 1;
	}

	int br = 0, bc1, bc2;
	used.resize(n, vector<vector<char>>(m, vector<char>(t)));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < t; ++k)
				if (!used[i][j][k])
				{
					int nr = dfs(i, j, k);
					if (br < nr)
					{
						br = nr;
						bc1 = color[i][j];
						bc2 = k;
					}
				}
	if (bc1 > bc2) swap(bc1, bc2);

	cout << br << '\n' << bc1 + 1 << ' ' << bc2 + 1 << '\n';

	return 0;
}