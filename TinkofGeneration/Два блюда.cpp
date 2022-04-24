#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, m; cin >> n >> m;
	vector<long long> a(n), s(n), p(n), b(m), t(m), q(m);
	for (long long i = 0; i < n; ++i) cin >> a[i] >> s[i] >> p[i];
	for (long long i = 0; i < m; ++i) cin >> b[i] >> t[i] >> q[i];

	vector<long long> asum(n + 1), bsum(m + 1);
	partial_sum(a.begin(), a.end(), asum.begin() + 1);
	partial_sum(b.begin(), b.end(), bsum.begin() + 1);

	if (*min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end()) && 
		*min_element(t.begin(), t.end()) == *max_element(t.begin(), t.end()))
	{
		vector<long long> psum(n + 1), qsum(m + 1);
		partial_sum(p.begin(), p.end(), psum.begin() + 1);
		partial_sum(q.begin(), q.end(), qsum.begin() + 1);

		long long res = 0;

		for (int i = 0; i <= n; ++i)
		{
			auto it = upper_bound(bsum.begin(), bsum.end(), s[0] - asum[i]) - bsum.begin();
			if (it > 0) res = max(res, psum[i] + qsum[it - 1]);
		}
		cout << res << '\n';

		return 0;
	}

	vector<vector<long long>> res(n + 1, vector<long long>(m + 1, -1e18)); res[0][0] = 0;
	for (long long i = 0; i <= n; ++i)
		for (long long j = 0; j <= m; ++j)
		{
			if (i + 1 <= n)
				res[i + 1][j] = max(res[i + 1][j], res[i][j] + (asum[i + 1] + bsum[j] <= s[i]) * p[i]);
			if (j + 1 <= m)
				res[i][j + 1] = max(res[i][j + 1], res[i][j] + (asum[i] + bsum[j + 1] <= t[j]) * q[j]);
		}

	cout << res[n][m] << '\n';

	return 0;
}