#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, l, k; cin >> n >> l >> k;

	vector<int> x(n), v(n);
	for (auto& i : x) cin >> i;
	for (auto& i : v) cin >> i;

	vector<vector<long long>> dp(n, vector<long long>(k + 1, 1e18));
	for (int i = n - 1; i >= 0; --i)
	{
		for (int tk = 0; tk <= k; ++tk)
		{
			if (n - i - 1 <= tk)
				dp[i][tk] = (l - x[i]) * 1ll * v[i];
			for (int j = i + 1; j - i - 1 <= tk && j < n; ++j)
				dp[i][tk] = min(dp[i][tk], dp[j][tk - (j - i - 1)] + (x[j] - x[i]) * 1ll * v[i]);
		}
	}

	cout << dp[0][k] << '\n';

	return 0;
}