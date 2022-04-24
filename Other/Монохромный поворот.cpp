#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1000000007;

long long qpow(long long a, long long k)
{
	if (k == 0) return 1;
	if (k % 2) return (qpow(a, k - 1) * a) % p;
	long long res = qpow(a, k / 2);
	return (res * res) % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;

	if (n % 2)
		cout << 0 << '\n';
	else
		cout << qpow(2, n * n / 4) << '\n';

	return 0;
}