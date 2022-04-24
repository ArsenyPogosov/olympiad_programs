#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

pair<long long, long long> GCD(long long a, long long b)
{
	if (a == 0) return { 0 , 1 };
	auto res = GCD(b % a, a);
	return { res.second - res.first * (b / a), res.first };
}

long long obr(long long x)
{
	return (GCD(x, p).first % p + p) % p;
}

vector<long long> f, obrf;

void build(long long n)
{
	++n;
	f.resize(n); obrf.resize(n); f[0] = obrf[0] = 1;
	for (long long i = 1; i < n; ++i)
	{
		f[i] = (f[i - 1] * i) % p;
		obrf[i] = obr(f[i]);
	}
}

long long C(long long n, long long k)
{
	if (n < k || k < 0) return 0;
	return ((((f[n] * obrf[k]) % p) * obrf[n - k]) % p);
}

long long res(long long n, long long m)
{
	return C(n - 1, m - 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m; cin >> n >> m;
	build(max(m, n) + 2);
	long long ans = 0;
	for (long long i = 0; i <= n; ++i)
	{
		ans += (res(m, n - i) * C(n, i)) % p;
		ans %= p;
	}
	cout << ans << '\n';

	return 0;
}