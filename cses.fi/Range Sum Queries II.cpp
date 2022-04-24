#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> a, fenv;

long long prefsum(long long i)
{
	long long res = 0;
	while (i >= 0)
	{
		res += fenv[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}

long long sum(long long l, long long r)
{
	return prefsum(r) - prefsum(l - 1);
}

void change(long long i, long long x)
{
	long long d = x - a[i];
	a[i] += d;
	while (i < n)
	{
		fenv[i] += d;
		i = (i | (i + 1));
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long q; cin >> n >> q; a.resize(n); fenv.resize(n);
	for (long long i = 0; i < n; ++i)
	{
		long long h; cin >> h;
		change(i, h);
	}
	while (q--)
	{
		long long a, b, c; cin >> a >> b >> c;
		if (a == 1)
			change(b - 1, c);
		if (a == 2)
			cout << sum(b - 1, c - 1) << '\n';
	}

	return 0;
}