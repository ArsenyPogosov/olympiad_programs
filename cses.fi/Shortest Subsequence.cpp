#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	string s; cin >> s; n = s.size();
	for (auto& i : s)
	{
		if (i == 'A') i = 0;
		if (i == 'C') i = 1;
		if (i == 'G') i = 2;
		if (i == 'T') i = 3;
	}
	vector<char> table{ 'A', 'C', 'G', 'T' };
	vector<vector<int>> nxt(n + 1, vector<int>(4));
	vector<int> last(4, n); nxt[n] = last;
	for (int i = n - 1; i >= 0; --i)
	{
		last[s[i]] = i;
		nxt[i] = last;
	}
	vector<int> dp(n + 2), p(n + 2); dp[n + 1] = -1; dp[n] = 1; p[n] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		int mn = 0;
		for (int j = 1; j < 4; ++j)
			if (dp[nxt[i][j] + 1] < dp[nxt[i][mn] + 1])
				mn = j;
		p[i] = mn;
		dp[i] = dp[nxt[i][mn] + 1] + 1;
	}
	for (int i = 0; i <= n; i = nxt[i][p[i]] + 1)
		cout << table[p[i]];
	cout << '\n';

	return 0;
}