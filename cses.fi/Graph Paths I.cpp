#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m, k, t = 30;
	cin >> n >> m >> k;
	vector<vector<vector<long long>>> res(t, vector<vector<long long>>(n, vector<long long>(n)));
	for (long long i = 0; i < m; ++i)
	{
		long long a, b; cin >> a >> b;
		++res[0][a - 1][b - 1];
	}
	for (long long i = 1; i < t; ++i)
		for (long long u = 0; u < n; ++u)
			for (long long v = 0; v < n; ++v)
				for (long long h = 0; h < n; ++h)
				{
					res[i][u][v] += res[i - 1][u][h] * res[i - 1][h][v];
					res[i][u][v] %= p;
				}
	vector<long long> ans(n); ans[0] = 1;
	for (long long i = t - 1; i >= 0; --i)
		if (k >= (1 << i))
		{
			k -= 1 << i;
			vector<long long> h(n);
			for (long long u = 0; u < n; ++u)
				for (long long v = 0; v < n; ++v)
				{
					h[u] += ans[v] * res[i][v][u];
					h[u] %= p;
				}
			ans = h;
		}
	cout << ans[n - 1] << '\n';

	return 0;
}