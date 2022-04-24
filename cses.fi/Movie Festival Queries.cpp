#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, q; cin >> n >> q; m = 21;
	vector<pair<int, int>> film(n);
	for (auto& i : film) cin >> i.first >> i.second;
	sort(film.rbegin(), film.rend());
	vector<vector<int>> nxt(m, vector<int>(1e6 + 2, 1e6 + 1));
	int mn = 1e6 + 1, last = 1e6;
	for (auto& i : film)
	{
		for (; last > i.first; --last)
			nxt[0][last] = mn;
		mn = min(mn, i.second);
	}
	for (; last >= 0; --last)
		nxt[0][last] = mn;
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];

	while (q--)
	{
		int a, b, res = 0; cin >> a >> b;
		for (int i = m - 1; i >= 0; --i)
			if (nxt[i][a] <= b)
				a = nxt[i][a], res += (1 << i);
		cout << res << '\n';
	}

	return 0;
}