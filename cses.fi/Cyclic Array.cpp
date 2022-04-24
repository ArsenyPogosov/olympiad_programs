#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n, m = 19;
long long k;
vector<long long> ps;

long long sum(long long l, long long r)
{
	return (l <= r ? ps[r] - (l > 0 ? ps[l - 1] : 0) : sum(l, n - 1) + sum(0, r));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	ps.resize(n); partial_sum(a.begin(), a.end(), ps.begin());
	vector<vector<long long>> nxt(m, vector<long long>(n));
	for (long long i = 0; i < n; ++i)
	{
		long long l = 1, r = n + 1;
		while (l + 1 < r)
		{
			long long h = (l + r) / 2;
			if (sum(i, (i + h - 1) % n) <= k)
				l = h;
			else
				r = h;
		}
		nxt[0][i] = l;
	}
	for (long long i = 1; i < m; ++i)
		for (long long j = 0; j < n; ++j)
			nxt[i][j] = nxt[i - 1][(j + nxt[i - 1][j]) % n] + nxt[i - 1][j];
	long long res = n;
	for (long long i = 0; i < n; ++i)
	{
		long long tres = 0, t = 0;
		for (long long j = m - 1; j >= 0; --j)
			if (t + nxt[j][(i + t) % n] < n)
				t += nxt[j][(i + t) % n], tres += (1 << j);
		res = min(res, tres + 1);
	}
	cout << res << '\n';

	return 0;
}