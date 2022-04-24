#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m = 19;
vector<vector<int>> nxt;

int kpar(int v, int k)
{
	for (int i = m - 1; i >= 0; --i)
		if (k >= (1 << i))
		{
			v = nxt[i][v];
			k -= (1 << i);
		}
	return v;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; nxt.resize(m, vector<int>(n));
	for (int i = 1; i < n; ++i) cin >> nxt[0][i], --nxt[0][i];
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
	while (q--)
	{
		int v, k; cin >> v >> k;
		int res = kpar(v - 1, k);
		if (res == 0 && kpar(v - 1, k - 1) == 0)
			res = -2;
		cout << res + 1 << '\n';
	}

	return 0;
}