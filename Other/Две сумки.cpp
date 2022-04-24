#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, y;
	cin >> n >> x >> y; ++x; ++y;
	vector<int> a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	vector<int> dp(x);
	vector<vector<char>> p(n, vector<char>(x));

	for (int i = 0; i < x && i < a[0]; ++i)
		dp[i] = b[0], p[0][i] = 1;

	for (int i = 1; i < n; ++i)
	{
		vector<int> ndp(x);
		for (int j = a[i]; j < x; ++j)
			ndp[j] = dp[j - a[i]];

		for (int j = 0; j < x; ++j)
			if (j < a[i] || ndp[j] > dp[j] + b[i])
				ndp[j] = dp[j] + b[i], p[i][j] = 1;

		for (auto& j : ndp)
			j = min(j, y);

		dp = ndp;
	}

	if (dp[x - 1] >= y)
	{
		cout << -1 << '\n';
		return 0;
	}

	string res;
	int i = n - 1, j = x - 1;
	while (i >= 0)
	{
		res += (p[i][j] ? 'y' : 'x');
		j -= (p[i][j] ? 0 : a[i]);
		--i;
	}
	reverse(res.begin(), res.end());
	cout << res << '\n';

	return 0;
}