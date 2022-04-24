#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> dp(m);
	{
		int h; cin >> h; --h;
		if (h == -1)
			dp = vector<int>(m, 1);
		else
			dp[h] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		vector<int> hdp = dp;
		for (int i = 1; i < m; ++i)
		{
			hdp[i] += dp[i - 1];
			hdp[i] %= p;
		}
		for (int i = 0; i < m -1; ++i)
		{
			hdp[i] += dp[i + 1];
			hdp[i] %= p;
		}
		dp = hdp;

		int h; cin >> h; --h;
		if (h != -1)
		{
			int x = dp[h];
			dp = vector<int>(m);
			dp[h] = x;
		}
	}
	int res = 0;
	for (auto& i : dp) res = (res + i) % p;
	cout << res << '\n';

	return 0;
}