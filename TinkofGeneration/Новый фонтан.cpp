#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;

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

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> w(n, vector<int>(m));
	for (auto& i : w)
		for (auto& j : i)
			cin >> j;

	set<pair<int, pair<int, int>>> edge;
	for (int i = 0; i < n; ++i)
		edge.emplace(w[i][0], pair<int, int>{ i, 0 });
	for (int i = 0; i < n; ++i)
		edge.emplace(w[i][m - 1], pair<int, int>{ i, m - 1 });
	for (int j = 0; j < m; ++j)
		edge.emplace(w[0][j], pair<int, int>{ 0, j });
	for (int j = 0; j < m; ++j)
		edge.emplace(w[n - 1][j], pair<int, int>{ n - 1, j });

	long long res = 0;
	vector<vector<char>> used(n, vector<char>(m));
	for (auto& i : edge)
	{
		if (used[i.second.first][i.second.second]) continue;
		used[i.second.first][i.second.second] = true;

		int d = i.first;
		queue<pair<int, int>> q;
		q.push(i.second);

		while (q.size())
		{
			int x = q.front().first, y = q.front().second; q.pop();

			for (auto& i : adj(x, y))
			{
				int nx = i.first, ny = i.second;
				if (used[nx][ny]) continue;

				if (w[nx][ny] > d)
				{
					edge.emplace(w[nx][ny], pair<int, int>{ nx, ny });
					continue;
				}

				used[nx][ny] = true;
				q.emplace(nx, ny);

				res += d - w[nx][ny];
			}
		}
	}

	cout << res << '\n';

	return 0;
}