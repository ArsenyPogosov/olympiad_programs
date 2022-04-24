#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> res(n, vector<int>(m, 1e9));
	while (k--)
	{
		int x, y, r; cin >> x >> y >> r; --x; --y;
		r = 1 - r * 2;
		int t = 1;
		for (int l = 1; l <= max(n, m) * 2 + 1; l += 2)
		{
			for (int j = 0; j < l; ++j, x -= 1, ++t)
				if (0 <= x && x < n && 0 <= y && y < m)
					res[x][y] = min(res[x][y], t);
			for (int j = 0; j < l; ++j, y += r, ++t)
				if (0 <= x && x < n && 0 <= y && y < m)
					res[x][y] = min(res[x][y], t);
			for (int j = 0; j < l + 1; ++j, x += 1, ++t)
				if (0 <= x && x < n && 0 <= y && y < m)
					res[x][y] = min(res[x][y], t);
			for (int j = 0; j < l + 1; ++j, y -= r, ++t)
				if (0 <= x && x < n && 0 <= y && y < m)
					res[x][y] = min(res[x][y], t);
		}
	}

	for (auto& i : res)
	{
		for (auto& j : i)
			cout << j << ' ';
		cout << '\n';
	}

	return 0;
}