#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; n -= m;
	int ts = 0, ms = 0;
	for (int i = 0; i < m; ++i)
	{
		char h; cin >> h;
		if (h == '(')
			++ts;
		else
			--ts;

		ms = min(ts, ms);
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	dp[0][0] = 1;
	for (int l = 1; l <= n; ++l)
		for (int s = 0; s <= l; ++s)
			dp[l][s] = (dp[l - 1][s + 1] + (s > 0 ? dp[l - 1][s - 1] : 0)) % p;

	int res = 0;
	for (int l = 0; l <= n; ++l)
		for (int s = max(0, -ms); s <= l; ++s)
			if (s + ts <= n - l)
				res = (res + dp[l][s] * 1ll * dp[n - l][s + ts]) % p;

	cout << res << '\n';

	return 0;
}