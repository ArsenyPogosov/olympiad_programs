#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> h(n), s(n);
	for (auto& i : h) cin >> i;
	for (auto& i : s) cin >> i;
	vector<int> dp(x + 1);
	for (int i = 0; i < n; ++i)
		for (int j = x; j >= h[i]; --j)
			dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
	cout << dp[x] << '\n';

	return 0;
}