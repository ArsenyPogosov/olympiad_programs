#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n);
	for (auto& i : a) cin >> i;

	int res = 1e9;
	for (int i = 0; i <= m; ++i)
	{
		vector<int> dp(i + 1, 1e9);
		dp[0] = 0;
		for (int t = 0; t < n; ++t)
		{
			for (int j = i; j >= 0; --j)
			{
				if ((t - j) % k != k - 1)
					dp[j] += a[t];
				if (j > 0)
				{
					if ((n - i + j - 1) % k == k - 1)
						dp[j] = min(dp[j], dp[j - 1]);
					else
						dp[j] = min(dp[j], dp[j - 1] + a[t]);
				}
				if (dp[j] > 1e9) dp[j] = 1e9;
			}
		}
		res = min(res, dp[i]);
	}

	cout << res << '\n';

	return 0;
}