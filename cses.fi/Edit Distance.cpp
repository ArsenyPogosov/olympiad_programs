#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b;
	int n = a.size(), m = b.size();
	int dp[5001];
	iota(dp, dp + 5001, 0);
	for (int i = 1; i <= n; ++i)
	{
		int prev = dp[0]; dp[0] = i;
		for (int j = 1; j <= m; ++j)
		{
			int h = dp[j];
			if (a[i - 1] == b[j - 1])
				dp[j] = prev;
			else
				dp[j] = min({ prev, dp[j], dp[j - 1] }) + 1;
			prev = h;
		}
	}
	/*for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			cout << dp[i][j] << '\n' << a.substr(0, i) << '\n' << b.substr(0, j) << "\n\n";
		}*/
	cout << dp[m] << '\n';

	return 0;
}