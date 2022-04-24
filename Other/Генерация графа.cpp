#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	if (n * m % 2)
	{
		if (5 <= n * m)
			m = (n * m + 1) / 2;
		else
			return 0;
	}
	else
	{
		m = n * m / 2;
	}

	vector<vector<int>> res(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n && m; ++j, --m)
			res[i][j] = res[j][i] = 1;

	cout << n << '\n';
	for (auto& i : res)
	{
		for (auto& j : i)
			cout << j << ' ';
		cout << '\n';
	}

	return 0;
}