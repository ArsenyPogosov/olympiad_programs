//source: file:///C:/Users/arsen/Downloads/13.11.19.%201%20%D0%B3%D1%80%D1%83%D0%BF%D0%BF%D0%B0.%20%D0%94%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D0%BA%D0%B0%20%D0%BF%D0%BE%20%D0%BF%D0%BE%D0%B4%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%B0%D0%BC%20%D0%B8%20%D0%BF%D1%80%D0%BE%D1%84%D0%B8%D0%BB%D1%8E.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("domino-covering-2.in");
ofstream fout("domino-covering-2.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

long long get(long long mask, long long i)
{
	return (mask >> i) & 1;
}

int main()
{
	long long n, m; cin >> n >> m;
	vector<vector<int>> hole(n, vector<int>(m));
	for (auto& i : hole) for (auto& j : i) { char h; cin >> h; j = (h == '.' ? 0 : 1); }
	vector<vector<vector<long long>>> dp(m + 2, vector<vector<long long>>(1 << n, vector<long long>(n)));
	dp[0][0][0] = 1;
	for (long long i = 0; i < m; ++i)
	{
		for (long long j = 0; j < n - 1; ++j)
		{
			for (long long mask = 0; mask < (1 << n); ++mask)
			{
				if (!get(mask, j))
				{
					if (hole[j][i]) 
					{
						dp[i][mask][j + 1] += dp[i][mask][j];
						continue; 
					}
					dp[i][mask | (1 << j)][j + 1] += dp[i][mask][j];
					if (!get(mask, j + 1))
						dp[i][mask | (1 << (j + 1))][j + 1] += dp[i][mask][j];
				}
				else
				{
					if (hole[j][i]) continue;
					dp[i][mask ^ (1 << j)][j + 1] += dp[i][mask][j];
				}
			}
		}
		for (long long mask = 0; mask < (1 << n); ++mask)
		{
			if (!get(mask, n - 1))
			{
				if (hole[n - 1][i])
				{
					dp[i + 1][mask][0] += dp[i][mask][n - 1];
					continue;
				}
				dp[i + 1][mask | (1 << (n - 1))][0] += dp[i][mask][n - 1];
			}
			else
			{
				if (hole[n - 1][i]) continue;
				dp[i + 1][mask ^ (1 << (n - 1))][0] += dp[i][mask][n - 1];
			}
		}
	}
	cout << dp[m][0][0];

	return 0;
}