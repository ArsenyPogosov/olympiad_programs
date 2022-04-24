#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int need(int n, int m, int i, int j)
{
	int res = 4;
	if (i == 0 || i == n - 1) --res;
	if (j == 0 || j == m - 1) --res;
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		vector<vector<int>> table(n, vector<int>(m));
		for (auto& i : table)
			for (auto& j : i)
				cin >> j;
		bool good = true;
		for (int i = 0; i < n && good; ++i)
			for (int j = 0; j < m; ++j)
			{
				if (table[i][j] > need(n, m, i, j))
				{
					good = false; break;
				}
			}
		if (!good)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n && good; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << need(n, m, i, j) << ' ';
			cout << '\n';
		}
	}

	return 0;
}