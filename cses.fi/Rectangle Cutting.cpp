#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b; cin >> a >> b;
	vector<vector<int>> dp(a + 1, vector<int>(b + 1));
	for (int i = 1; i <= a; ++i)
		for (int j = 1; j <= b; ++j)
		{
			if (i == j) continue;
			dp[i][j] = i * j;
			for (int d = 1; d < i; ++d)
				dp[i][j] = min(dp[i][j], dp[d][j] + dp[i - d][j] + 1);
			for (int d = 1; d < j; ++d)
				dp[i][j] = min(dp[i][j], dp[i][d] + dp[i][j - d] + 1);
		}
	cout << dp[a][b] << '\n';

	return 0;
}