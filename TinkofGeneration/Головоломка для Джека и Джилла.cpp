#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

vector<long long> obr, fact, obrfact;

void init(long long l)
{
	obr.resize(l); obr[1] = 1;
	for (long long i = 2; i < l; ++i)
		obr[i] = p - p / i * obr[p % i] % p;

	fact.resize(l); fact[0] = 1;
	for (long long i = 1; i < l; ++i)
		fact[i] = fact[i - 1] * i % p;

	obrfact.resize(l); obrfact[0] = 1;
	for (long long i = 1; i < l; ++i)
		obrfact[i] = obrfact[i - 1] * obr[i] % p;
}

long long C(long long n, long long k)
{
	return fact[n] * obrfact[k] % p * obrfact[n - k] % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long m, n, r; cin >> m >> n >> r;

	init(m + 2);

	cout << C(m, n * 2) * C(2 * n + 1, n) % p * obr[2 * n + 1] % p;

	return 0;
}