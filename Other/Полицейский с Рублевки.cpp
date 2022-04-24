#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long truesqrt(long long x)
{
	if (x < 0) return -1;
	long long res = (long long)sqrt(x);
	for (int i = -10; i <= 10; ++i)
		if ((res + i) * (res + i) == x)
			return abs(res + i);
	return -1;
}
int main()
{
	long long n; cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	long long m = 0, d = 0;
	for (auto& i : a) m += i;
	if (m % n != 0)
	{
		cout << "Impossible\n";
		return 0;
	}
	m /= n;
	for (auto& i : a) d += (i - m) * (i - m);
	if (d % n != 0)
	{
		cout << "Impossible\n";
		return 0;
	}
	d /= n;
	for (int i = 0; i < n; ++i)
	{
		long long s = m + a[i], ps = d + (a[i] - m) * (a[i] - m);
		long long k1 = 2, k2 = -2 * s, k3 = s*s + 2 * m * m - 2 * s * m - ps;
		long long diskr = truesqrt(k2 * k2 - 4 * k1 * k3);
		if (diskr == -1) continue;
		if ((-k2 - diskr) % (2 * k1) == 0)
		{
			long long res = (-k2 - diskr) / (2 * k1);
			cout << "Possible\n";
			cout << i + 1 << ' ' << res << ' ' << s - res;
			return 0;
		}
		if ((-k2 + diskr) % (2 * k1) == 0)
		{
			long long res = (-k2 + diskr) / (2 * k1);
			cout << "Possible\n";
			cout << i + 1 << ' ' << res << ' ' << s - res;
			return 0;
		}
	}
	cout << "Impossible\n";
	return 0;

	return 0;
}