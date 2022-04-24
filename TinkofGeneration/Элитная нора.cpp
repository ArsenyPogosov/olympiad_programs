#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e8;

long long n, m;
vector<vector<long long>> a;

long long solve(long long x)
{
	vector<vector<long long>> ps(n, vector<long long>(m + 1));
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < m; ++j)
			ps[i][j + 1] = ps[i][j] + (a[i][j] < x ? -INF : 1);

	long long res = 0;
	for (long long i = 0; i < m; ++i)
		for (long long j = i; j < m; ++j)
		{
			vector<long long> mass(n + 1);
			for (long long k = 0; k < n; ++k)
				mass[k + 1] = mass[k] + ps[k][j + 1] - ps[k][i];

			long long tmn = 0;
			for (long long i = 1; i <= n; ++i)
			{
				tmn = min(tmn, mass[i]);
				res = max(res, mass[i] - tmn);
			}
		}

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long k; cin >> n >> m >> k;
	a.resize(n, vector<long long>(m));
	for (auto& i : a)
		for (auto& j : i)
			cin >> j;

	long long l = 0, r = 1e9 + 1, lres = -1;
	while (l + 1 < r)
	{
		long long m = (l + r) / 2;
		long long nres = solve(m);
		if (nres >= k)
		{
			l = m;
			lres = nres;
		}
		else
		{
			r = m;
		}
	}
	cout << l << ' ' << lres << '\n';

	return 0;
}