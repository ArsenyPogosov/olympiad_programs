#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s; cin >> n; s = n * (n + 1) / 2 / 2;
	if (n * (n + 1) % 4)
	{
		cout << "0\n";
		return 0;
	}
	vector<long long> dp(s + 1); dp[0] = 1;
	for (int i = 1; i < n; ++i)
		for (int j = s; j >= i; --j)
			dp[j] = (dp[j] + dp[j - i]) % p;
	cout << dp[s] << '\n';

	return 0;
}