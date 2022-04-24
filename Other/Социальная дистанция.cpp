#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	
	vector<vector<char>> used(n, vector<char>(m));
	set<pair<int, pair<int, int>>> bye;

	for (int i = 0; i < k; ++i)
	{
		int s, f; cin >> s >> f;
		while (bye.size() && bye.begin()->first <= s)
		{
			used[bye.begin()->second.first][bye.begin()->second.second] = false;
			bye.erase(bye.begin());
		}

		vector<vector<int>> dist(n, vector<int>(m, 1e9));
		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (used[i][j])
				{
					dist[i][j] = 0;
					q.emplace(i, j);
				}

		while (q.size())
		{
			int x = q.front().first, y = q.front().second; q.pop();

			vector<pair<int, int>> step{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			for (auto& i : step)
			{
				int nx = x + i.first, ny = y + i.second;
				if (!(0 <= nx && nx < n && 0 <= ny && ny < m))
					continue;

				if (dist[nx][ny] > dist[x][y] + 1)
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.emplace(nx, ny);
				}
			}
		}

		int x = 0, y = 0, len = -1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (len < dist[i][j])
				{
					len = dist[i][j];
					x = i; y = j;
				}

		if (used[x][y])
		{
			cout << -1 << ' ' << -1 << '\n';
			continue;
		}

		bye.emplace(f, pair<int, int>{x, y});
		used[x][y] = true;
		cout << x + 1 << ' ' << y + 1 << '\n';
	}

	return 0;
}