#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, t; cin >> n >> m >> k;
	vector<int> x(k), y(k), s(k), f(k);
	for (int i = 0; i < k; ++i)
		cin >> x[i] >> y[i] >> s[i] >> f[i], --x[i], --y[i];
	++k;
	x.push_back(0);
	y.push_back(0);
	s.push_back(0);
	f.push_back(1);
	t = *max_element(f.begin(), f.end());

	vector<int> tline(t, -1), nxt(t, -1);
	for (int i = 0; i < k; ++i)
		for (int j = s[i]; j < f[i]; ++j)
			tline[j] = i;

	for (int i = t - 2; i >= 0; --i)
	{
		if (tline[i] != tline[i + 1] && tline[i + 1] != -1)
			nxt[i] = i + 1;
		else
			nxt[i] = nxt[i + 1];
	}

	vector<int> dp(t);

	for (int i = t - 1; i >= 0; --i)
	{
		if (tline[i] == -1) continue;

		dp[i] = 1;
		for (int cnt = 0, tek = i; cnt < n + m; ++cnt)
		{
			tek = nxt[tek];
			if (tek == -1) break;

			int d = abs(x[tline[i]] - x[tline[tek]]) + abs(y[tline[i]] - y[tline[tek]]) + (i == 0);
			if (i + d < f[tline[tek]])
				dp[i] = max(dp[i], 1 + dp[max(i + d, tek)]);
		}
	}

	cout << dp[0] - 1 << '\n';


	return 0;
}