#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	vector<int> r1(n), r2(n), c1(m), c2(m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char h; cin >> a[i][j];
			if (a[i][j] == '-')
			{
				--r1[i];
				--c1[j];
			}
			if (a[i][j] == '?')
			{
				++r2[i];
				++c2[j];
			}
			if (a[i][j] == '+')
			{
				++r1[i];
				++c1[j];
			}
		}

	int res = -1e6;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			res = max(res, r1[i] - c1[j] + r2[i] + c2[j] - (a[i][j] == '?' ? 2 : 0));
		}
	cout << res << '\n';


	return 0;
}