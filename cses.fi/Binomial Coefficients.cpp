#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

pair<long long, long long> GCD(long long a, long long b)
{
	if (a == 0) return {0, 1};
	auto res = GCD(b % a, a);
	return { res.second - res.first * (b / a), res.first };
}

long long obr(long long x)
{
	return ((GCD(x, p).first % p + p) % p);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long m = 1e6 + 1;
	vector<long long> f(m), obrf(m); f[0] = obrf[0] = 1;
	for (long long i = 1; i < m; ++i)
	{
		f[i] = (f[i - 1] * i) % p;
		obrf[i] = obr(f[i]);
	}
	long long n; cin >> n;
	while (n--)
	{
		long long a, b; cin >> a >> b;
		cout << (((f[a] * 1ll * obrf[b]) % p) * 1ll * obrf[a - b]) % p << '\n';
	}

	return 0;
}