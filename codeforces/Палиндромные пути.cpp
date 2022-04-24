#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (auto& i : a)
			for (auto& j : i)
			{
				cin >> j;
			}
		int res = 0;
		for (int d = 1; d <= (n + m - 1) / 2; ++d)
		{
			int count[2]; count[0] = count[1] = 0;
			for (int i = min(n - 1, d - 1); i >= 0; --i)
			{
				int j = d - i - 1;
				if (!(0 <= j && j < m)) continue;
				++count[a[i][j]];
				++count[a[n - i - 1][m - j - 1]];
			}
			res += min(count[0], count[1]);
		}
		cout << res << '\n';
	}

	return 0;
}