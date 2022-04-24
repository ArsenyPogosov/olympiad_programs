#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n, x;
vector<long long> d, pf, spf;

long long supersum(long long a, long long b)
{
	if (a > b) return 0;
	return (a + b) * (b - a + 1) / 2;
}

long long sumlr(long long l, long long r)
{
	if (l > r) return sumlr(l, n - 1) + sumlr(0, r);
	return pf[r] - (l > 0 ? pf[l - 1] : 0);
}

long long ssumlr(long long l, long long r)
{
	if (l > r) return ssumlr(l, n - 1) + ssumlr(0, r);
	return spf[r] - (l > 0 ? spf[l - 1] : 0);
}

long long best(long long i, long long j, long long s)
{
	if (i == j)
		return supersum(max(0ll, d[i] - s + 1), d[i]);
	s = min(s, d[i] + d[j]);
	if (d[i] - (s - d[j]) <= d[j])
	{
		long long take = min(d[j], s);
		return supersum(1, take) + supersum(d[i] - (s - take) + 1, d[i]);
	}
	else
	{
		long long take = min(d[i], s);
		return supersum(d[i] - take + 1, d[i]) + supersum(1, (s - take));
	}
}

long long findj(long long i, long long s = x)
{
	long long l = 0, r = n;
	while (l + 1 < r)
	{
		long long m = (l + r) / 2; int sum = sumlr((i + 1) % n, (i + m) % n);
		if (d[i] - (x - sum) > d[(i + l) % n])
			l = m;
		else
			r = m;
	}
	return best(i, (i + r) % n, x - sumlr((i + 1) % n, (i + r + n - 1) % n)) + ssumlr( (i + 1) % n, (i + r + n - 1) % n);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> x; d.resize(n); pf.resize(n); spf.resize(n);
	for (auto& i : d) cin >> i;
	pf[0] = d[0];
	for (long long i = 1; i < n; ++i)
		pf[i] = pf[i - 1] + d[i];
	spf[0] = supersum(1, d[0]);
	for (long long i = 1; i < n; ++i)
		spf[i] = spf[i - 1] + supersum(1, d[i]);
	long long res = -1;
	for (long long i = 0; i < n; ++i)
	{
		res = max(res, best(i, (i + 1) % n, x));
		if (d[i] >= x)
		{
			res = max(res, supersum(d[i] - x + 1, d[i]));
			continue;
		}
		res = max(res, findj(i));
	}
	cout << res << '\n';

	return 0;
}