#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 998244353;

pair<long long, long long> gcd(long long a, long long b)
{
	if (a == 0) return { 0, 1 };
	auto res = gcd(b % a, a);
	swap(res.first, res.second);
	res.first = ((res.first - (b / a) * res.second) % p + p) % p;

	return res;
}

long long obr(long long x)
{
	return gcd(x, p).first;
}

vector<long long> fact;

long long c(long long n, long long k)
{
	return fact[n] * obr(fact[k]) % p * obr(fact[n - k]) % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fact.resize(1e5 + 5);
	fact[0] = 1;
	for (long long i = 1; i < 1e5 + 5; ++i)
		fact[i] = fact[i - 1] * i % p;

	long long t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		string s; cin >> s; s += '0';
		long long a = 0, b = 0, tek = 0;
		for (long long i = 0; i < n + 1; ++i)
		{
			if (s[i] == '0')
			{
				a += tek / 2;
				b += tek % 2;
				tek = 0;
			}
			else
				++tek;
		}

		cout << c(n - b - a, a) << '\n';
	}

	return 0;
}