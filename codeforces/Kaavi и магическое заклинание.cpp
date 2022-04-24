#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int ans(string a, string b)
{
	int n = a.size();
	int l = 0, r = n - 1, count = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		bool h = false;
		int mu = 0;
		if (a[i] == b[l])
		{
			h = true;
			++mu; ++l;
		}
		if (a[i] == b[r])
		{
			++mu;
			if (!h) --r;
		}
		count *= mu;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<int>> su(n, vector<int>(m + 1));
	su[0][0] = 2;
	if (s[0] = t[m - 1]) su[0][1] = 2;
	for (int i = 1; i < n; ++i)
	{
		su[i][0] = i * 2 + 2;
		for (int j = 1; j <= min(m, i + 1); ++j)
		{
			if (j < i + 1)
			{
				su[i][j] = su[i - 1][j];
				su[i][j] += su[i - 1][j - 1] * (s[i] == t[m - j]);
			}
			else
			{
				su[i][j] = ans(s.substr(0, i + 1), t.substr(m - j, j));
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; ++i)
		count += su[i][m];
	cout << count << '\n';

	return 0;
}