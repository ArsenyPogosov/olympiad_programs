#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	vector<long long> x(n), ps(n);
	for (auto& i : x) cin >> i;
	partial_sum(x.begin(), x.end(), ps.begin());
	vector<long long> dp(n);
	for (long long i = n - 1; i >= 0; --i)
	{
		dp[i] = x[i];
		for (long long j = i + 1; j < n; ++j)
		{
			dp[j] = max(x[i] + ps[j] - ps[i] - dp[j],
				x[j] + ps[j - 1] - (i > 0 ? ps[i - 1] : 0) - dp[j - 1]);
		}
	}
	cout << dp[n - 1] << '\n';

	return 0;
}