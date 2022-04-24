#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<char>> mp(n, vector<char>(m));
	for (auto& i : mp)
		for (auto& j : i)
			cin >> j;

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n / 2 + 1, -INF)));
	vector<vector<vector<int>>> p(n, vector<vector<int>>(m, vector<int>(n / 2 + 1, -1)));

	for (int i = 0; i < m; ++i)
		if (mp[n - 1][i] == 'M')
			dp[n - 1][i][0] = 0;

	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 0; j < m; ++j)
			for (int k = 0; k <= n / 2 && k <= i + 2; ++k)
			{
				int kk;
				if (mp[i][j] == '(')      kk = k - 1;
				else if (mp[i][j] == ')') kk = k + 1;
				else                      kk = k;
				if (kk < 0 || kk > n / 2) continue;

				for (int jj = j - 1; jj <= j + 1; ++jj)
				{
					if (jj < 0 || jj >= m) continue;
					if (mp[i + 1][jj] == '*') continue;
					if (dp[i][j][k] < dp[i + 1][jj][kk])
					{
						dp[i][j][k] = dp[i + 1][jj][kk];
					}
				}

				if ((mp[i][j] == '(' || mp[i][j] == ')') && dp[i][j][k] > -INF)
					++dp[i][j][k];
			}
	}

	vector<vector<vector<int>>> s(n, vector<vector<int>>(m, vector<int>(n / 2 + 1, 0)));
	vector<vector<vector<int>>> h(n, vector<vector<int>>(m, vector<int>(n / 2 + 1, 0)));
	vector<vector<vector<int>>> ldist(n + 1);
	for (int i = n - 2; i >= 0; --i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k <= n / 2 && k <= i + 2; ++k)
				if (dp[i][j][k] >= 0)
					ldist[dp[i][j][k]].push_back(vector<int>{i, j, k});

	for (int t = 0; t <= n; ++t)
	{
		vector<vector<int>> srt;
		for (auto& tt : ldist[t])
		{
			int i = tt[0], j = tt[1], k = tt[2];
			int kk;
			if (mp[i][j] == '(')      kk = k - 1;
			else if (mp[i][j] == ')') kk = k + 1;
			else                      kk = k;
			if (kk < 0 || kk > n / 2) continue;

			int ts = 1e9; int f = 0;
			if (mp[i][j] == '(') f = 1;
			if (mp[i][j] == ')') f = 1;
			for (int jj = j - 1; jj <= j + 1; ++jj)
			{
				if (jj < 0 || jj >= m) continue;
				if (mp[i + 1][jj] == '*') continue;
				if (t - f < dp[i + 1][jj][kk] ||
					(t - f == dp[i + 1][jj][kk] && ts > s[i + 1][jj][kk]))
				{
					ts = s[i + 1][jj][kk];
					p[i][j][k] = jj;
				}
			}

			if (mp[i][j] == '(')
				h[i][j][k] = -1;
			else if (mp[i][j] == ')')
				h[i][j][k] = 1;
			else if (p[i][j][k] != -1)
				h[i][j][k] = h[i + 1][p[i][j][k]][kk];

			s[i][j][k] = ts;
			srt.push_back(vector<int>{ts, h[i][j][k], i, j, k});
		}
		sort(srt.begin(), srt.end());
		int tek = -1;
		vector<int> prev{ -1, -1 };
		for (int j = 0; j < srt.size(); ++j)
		{
			if (srt[j][0] != prev[0] || srt[j][1] != prev[1])
			{
				++tek;
				prev[0] = srt[j][0];
				prev[1] = srt[j][1];
			}
			s[srt[j][2]][srt[j][3]][srt[j][4]] = tek;
		}
	}

	int bi = 0, bj = 0, bst = 0;

	for (int j = 0; j < m; ++j)
		if (dp[0][j][0] > bst || (dp[0][j][0] == bst && s[0][j][0] < s[bi][bj][0]))
		{
			bst = dp[0][j][0];
			bi = 0;
			bj = j;

		}
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mp[i][j] == '*' && (dp[i][j][0] > bst || (dp[i][j][0] == bst && s[i][j][0] < s[bi][bj][0])))
			{
				bst = dp[i][j][0];
				bi = i;
				bj = j;
			}

	string res = "";
	int bc = 0;
	for (; bi < n; ++bi)
	{
		int nbj = p[bi][bj][bc];
		if (mp[bi][bj] == '(')
		{
			res += '(';
			--bc;
		}
		if (mp[bi][bj] == ')')
		{
			res += ')';
			++bc;
		}
		bj = nbj;
	}

	cout << res.size() << '\n';
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i];
	cout << '\n';

	return 0;
}