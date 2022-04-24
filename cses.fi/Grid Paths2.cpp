#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<char>> mp(n, vector<char>(n));
	for (auto& i : mp)
		for (auto& j : i)
			cin >> j;
	vector<vector<int>> d(n, vector<int>(n));
	d[0][0] = (mp[0][0] == '.');
	for (int i = 1; i < n; ++i)
	{
		d[i][0] = d[i - 1][0] * (mp[i][0] == '.');
		d[0][i] = d[0][i - 1] * (mp[0][i] == '.');
	}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			d[i][j] = (d[i - 1][j] + d[i][j - 1]) * (mp[i][j] == '.') % p;
	cout << d[n - 1][n - 1] << '\n';

	return 0;
}