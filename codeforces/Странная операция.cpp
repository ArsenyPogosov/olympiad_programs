#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size(), c = 0;
	vector<int> type, count;
	for (int i = 0; i < n; ++i, ++c)
	{
		type.push_back(s[i] - '0'); count.push_back(1);
		for (; (i + 1 < n) && (s[i + 1] - '0' == type[c]); ++i, ++count[c]);
	}
	vector<int> dp(c);
	int tot1 = 1;
	stack<pair<int, int>> tot0;
	for (int i = 0; i < c; ++i)
	{
		if (type[i])
		{
			dp[i] = (tot1 * 1ll * count[i]) % p;
		}
		else
		{
			int ttot = (i > 0 ? dp[i - 1] : 1);
			dp[i] = (ttot * 1ll * count[i]) % p;
			while (tot0.size() && tot0.top().first <= count[i])
			{
				int d = count[i] - tot0.top().first, dtot = tot0.top().second;
				tot0.pop(); ttot += dtot;
				dp[i] = (dp[i] + dtot * 1ll * d) % p;
			}
			if (i > 0)
				tot0.emplace(ttot, dp[i]);
			tot1 += dp[i]; tot1 %= p;
		}
	}
	long long res = 0;
	for (int i = 0; i < c; ++i)
		if (type[i] == 1)
			res += dp[i];
	if (!type[c - 1])
		res += dp[c - 1];
	cout << res % p << '\n';

	return 0;
}