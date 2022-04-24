#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double t = clock();

	int n = 300, m = 300, c = 1e9; cin >> n >> m >> c;
	c = min(c, (n + m - 1) * 2);

	vector<vector<char>> mp(n, vector<char>(m));
	for (auto& i : mp)
		for (auto& j : i)
		{
			j = rand() % 2 + 1;
			cin >> j, j = (j == '.' ? 1 : 2);
		}

	long long res = 0;
	vector<vector<vector<int>>> col(n, vector<vector<int>>(m, vector<int>(2, 0)));

	for (int cc = 1; cc < col[0][0].size() && cc < 2; ++cc)
	{

		for (int j = 0; j < m; ++j)
		{
			int l = 0, r = 0, tc = 0;
			vector<int> line(n + 1);
			if (cc <= n * 2)
				while (l < n)
				{
					while (r < n && tc < cc)
						tc += mp[r++][j];
					if (tc < cc) break;

					if (tc == cc)
					{
						++line[l];
						--line[r];
						tc -= mp[l++][j];
					}

					while (tc > cc)
						tc -= mp[l++][j];
				}

			int tr = 0;
			for (int i = 0; i < n; ++i)
			{
				tr += line[i];
				col[i][j][cc] = tr + col[i][j][cc - 1];
			}
		}
	}

	for (int cc = c; cc >= 1; --cc)
	{
		int ccc = c - cc + 2;
		for (int j = 0; j < m; ++j)
		{
			int l = 0, r = 0, tc = 0;
			vector<int> line(n + 1);
			if (ccc <= n * 2)
				while (l < n)
				{
					while (r < n && tc < ccc)
						tc += mp[r++][j];
					if (tc < ccc) break;

					if (tc == ccc)
					{
						++line[l];
						--line[r];
						tc -= mp[l++][j];
					}

					while (tc > ccc)
						tc -= mp[l++][j];
				}

			int tr = 0;
			for (int i = 0; i < n; ++i)
			{
				tr += line[i];
				col[i][j][0] = col[i][j][1];
				col[i][j][1] += tr;
			}
		}

		if (cc <= m * 2)
		for (int i = 0; i < n; ++i)
		{
			int l = 0, r = 0, tc = 0;
			vector<int> line(m + 1);
			while (l < m)
			{
				while (r < m && tc < cc)
					tc += mp[i][r++];
				if (tc < cc) break;

				if (tc == cc)
				{
					++line[l];
					--line[r];
					tc -= mp[i][l++];
				}

				while (tc > cc)
					tc -= mp[i][l++];
			}

			int tr = 0;
			for (int j = 0; j < m; ++j)
			{
				tr += line[j];
				res += tr * 1ll * col[i][j][mp[i][j] - 1];
			}
		}
	}

	cout << res << '\n';

	//cout << (clock() - t) / CLOCKS_PER_SEC << '\n';

	return 0;
}