#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long p = 998244353;

pair<long long, long long> GCD(long long a, long long b)
{
	if (b == 0) return { 1, 0 };
	long long k = a / b;
	auto ans = GCD(b, a - k * b);
	return { ans.second, ans.first - k * ans.second };
}

long long obr(long long x)
{
	return (GCD(x, p).first % p + p) % p;
}

long long N = 5 * 1e5 + 1;
vector<long long> fact(5 * 1e5 + 1);

long long c(long long n, long long k)
{
	if (n < k) return 0;
	return (((fact[n] * obr(fact[k])) % p) * obr(fact[n - k])) % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = 1;
	for (long long i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % p;
	long long n, k; cin >> n >> k;
	long long res = 0;
	for (long long i = 1; i <= n; ++i)
	{
		res += c(n / i - 1, k - 1);
		res %= p;
	}
	cout << res << '\n';

	return 0;
}