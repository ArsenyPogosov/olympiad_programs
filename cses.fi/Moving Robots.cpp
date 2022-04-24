#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> move(int x, int y)
{
	vector<pair<int, int>> res, step{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	for (auto& s : step)
	{
		int nx = x + s.first, ny = y + s.second;
		if (0 <= nx && nx < 8 && 0 <= ny && ny < 8)
			res.emplace_back(nx, ny);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = 8, k, m = 7; cin >> k;
	vector<vector<vector<vector<vector<double>>>>> prob(m, \
		vector<vector<vector<vector<double>>>>(n, \
			vector<vector<vector<double>>>(n, \
				vector<vector<double>>(n, \
					vector<double>(n, \
						0)))));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			auto m = move(i, j);
			for (auto& x : m)
				prob[0][i][j][x.first][x.second] = 1.0 / m.size();
		}
	for (int i = 1; i < m; ++i)
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < n; ++b)
				for (int c = 0; c < n; ++c)
					for (int d = 0; d < n; ++d)
						for (int x = 0; x < n; ++x)
							for (int y = 0; y < n; ++y)
								prob[i][a][b][c][d] += prob[i - 1][a][b][x][y] * prob[i - 1][x][y][c][d];
	vector<vector<vector<vector<double>>>> res(n, \
		vector<vector<vector<double>>>(n, \
			vector<vector<double>>(n, \
				vector<double>(n, \
					0))));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			res[i][j][i][j] = 1;
	for (int i = m - 1; i >= 0; --i)
		if (k >= (1 << i))
		{
			k -= (1 << i);
			vector<vector<vector<vector<double>>>> nres(n, \
				vector<vector<vector<double>>>(n, \
					vector<vector<double>>(n, \
						vector<double>(n, \
							0))));
			for (int a = 0; a < n; ++a)
				for (int b = 0; b < n; ++b)
					for (int c = 0; c < n; ++c)
						for (int d = 0; d < n; ++d)
							for (int x = 0; x < n; ++x)
								for (int y = 0; y < n; ++y)
									nres[a][b][c][d] += res[a][b][x][y] * prob[i][x][y][c][d];
			res = nres;
		}
	vector<vector<double>> ans(n, vector<double>(n, 1));
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < n; ++b)
			for (int c = 0; c < n; ++c)
				for (int d = 0; d < n; ++d)
					ans[a][b] *= 1 - res[c][d][a][b];
	double superduperfinalansver = 0;
	for (auto& i : ans)
		for (auto& j : i)
			superduperfinalansver += j;
	cout << fixed << setprecision(6) << superduperfinalansver << '\n';

	return 0;
}