//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("numbers.in");
ofstream fout("numbers.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

const long long p = 1e9 + 7;
vector<vector<long long>> fract(10, vector<long long>(10, -1));
vector<long long> fact(100);

void buildfact()
{
	fact[0] = 1;
	for (long long i = 1; i < 100; ++i) fact[i] = (fact[i - 1] * i) % p;
}

long long C(long long n, long long k)
{
	long long res = 1;
	for (long long i = n - k + 1; i <= n; ++i) res *= i;
	res /= fact[k];
	return res % p;
}

long long Fract(long long d, long long n)
{
	if (n > d) return 0;
	if (n == d) return 1;
	if (n == 0) return 0;

	if (fract[d][n] != -1) return fract[d][n];
	fract[d][n] = 0;
	for (long long i = 1; i <= d; ++i)
		fract[d][n] = (fract[d][n] + Fract(d - i, n - 1)) % p;
	return fract[d][n];
}

long long h(long long n, long long i)
{
	long long res = 1;
	for (long long d = 1; d < 10 - i; ++d)
	{
		for (long long j = 1; j <= d; ++j)
			res = (res + Fract(d, j)*C(n, j)) % p;
	}
	return res;
}

long long ans(string x)
{
	long long t = 0, res = 0, n = x.size();
	for (long long i = 0; i < n; ++i)
	{
		for (long long j = t; j < x[i] - '0'; ++j)
			res = (res + h(n - i - 1, j)) % p;
		if (x[i] - '0' < t) break;
		t = x[i] - '0';
	}
	return res;
}

long long good(string n)
{
	for (int i = 1; i < n.size(); ++i)
		if (n[i - 1] > n[i])
			return 0;
	return 1;
}

int main()
{
	string l, r; cin >> l >> r;
	buildfact();
	cout << (ans(r) - ans(l) + p * 2 + good(r)) % p << '\n';

	return 0;
}