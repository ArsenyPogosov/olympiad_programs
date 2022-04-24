#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> h(n, vector<int>(m));
	for (int i = 0; i < k; ++i)
	{
		int a, b; cin >> a >> b;
		h[a - 1][b - 1] = 1;
	}

	cout << n * m - k << '\n';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!h[i][j])
				cout << i + 1 << ' ' << j + 1 << '\n';

	return 0;
}