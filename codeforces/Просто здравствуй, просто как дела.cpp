#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

long long qpow(long long x, long long pow)
{
	if (pow == 0) return 1;
	if (pow % 2 == 1) return qpow(x, pow - 1) * x % p;
	long long res = qpow(x, pow / 2);
	return res * res % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	if (n == 0)
	{
		cout << 125 + 1 + 1 << '\n';
		return 0;
	}
	long long h = qpow(2, n - 1), hh = (n * (n + 1) / 2) % p;

	cout << ((((h * 2 - 1) * qpow(n + 1, n) % p * n % p + (h - 1) + n * h % p + h * 2 + hh * hh % p - 1) % p) + p) % p << '\n';

	return 0;
}