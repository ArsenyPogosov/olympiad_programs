#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		vector<vector<int>> ps(k, vector<int>(n + 1));
		for (int i = 1; i <= n; ++i)
			for (int j = k - 1; j >= 0; --j)
			{
				char h; cin >> h;
				ps[j][i] = ps[j][i - 1] + (h - '0');
			}
		
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k, 1e8)));

		for (int len = 1; len <= n; ++len)
			for (int i = 0; i + len - 1 < n; ++i)
				for (int x = 0; x < k; ++x)
				{
					int j = i + len - 1;
					if (len == 1) dp[i][j][x] = 0;
					for (int t = i; t <= j + 1; ++t)
					{
						int tres = 0;
						tres += ps[x][t] - ps[x][i];
						if (t <= j)
							tres += (j - t + 1) - (ps[x][j + 1] - ps[x][t]);
						if (i + 1 < t)
						{
							if (x != 0)
								tres += dp[i][t - 1][x - 1];
						}
						if (t + 1 <= j)
						{
							if (x != 0) 
								tres += dp[t][j][x - 1];
						}

						dp[i][j][x] = min(dp[i][j][x], tres);
					}
				}

		cout << dp[0][n - 1][k - 1] << '\n';
	}

	return 0;
}