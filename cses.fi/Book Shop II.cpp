#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> h(n), s(n), k(n);
	for (auto& i : h) cin >> i;
	for (auto& i : s) cin >> i;
	for (auto& i : k) cin >> i;

	for (int i = 0; i < n; ++i)
		if (k[i] > 2)
		{
			h.push_back(h[i] * 2);
			s.push_back(s[i] * 2);
			k.push_back((k[i] - 1) / 2);
			++n;
			k[i] = 2 - k[i] % 2;
		}

	vector<int> dp(x + 1);
	for (int i = 0; i < n; ++i)
		for (int t = 0; t < k[i]; ++t)
			for (int j = x; j >= h[i]; --j)
				dp[j] = max(dp[j], dp[j - h[i]] + s[i]);

	cout << dp[x];

	return 0;
}