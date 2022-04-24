#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

bool get(int mask, int i)
{
	return (mask >> i) & 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n, vector<long long>((1 << n))));
	dp[0][0][0] = 1;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			for (int mask = 0; mask < (1 << n); ++mask)
			{
				dp[i][j][mask] %= p;
				if (get(mask, j))
				{
					dp[i + (j == n - 1)][(j + 1) % n][mask ^ (1 << j)] += dp[i][j][mask];
					continue;
				}
				dp[i + (j == n - 1)][(j + 1) % n][mask ^ (1 << j)] += dp[i][j][mask];
				if (j + 1 < n && !get(mask, j + 1))
					dp[i + (j == n - 1)][(j + 1) % n][mask ^ (1 << (j + 1))] += dp[i][j][mask];
			}

	cout << dp[m - 1][n - 1][1 << (n - 1)] << '\n';

	return 0;
}