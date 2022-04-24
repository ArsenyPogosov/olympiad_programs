#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<vector<int>> next(33, vector<int>(n));
	for (auto& i : next[0]) cin >> i, --i;
	for (int i = 1; i < 33; ++i)
		for (int j = 0; j < n; ++j)
			next[i][j] = next[i - 1][next[i - 1][j]];

	while (q--)
	{
		int x, k; cin >> x >> k; --x;
		for (int i = 0; k > 0; ++i, k >>= 1)
			if (k % 2)
				x = next[i][x];
		cout << x + 1 << '\n';
	}

	return 0;
}