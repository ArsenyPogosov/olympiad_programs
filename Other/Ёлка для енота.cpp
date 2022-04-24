#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 998244353;
const long long div2 = (p + 1) / 2;

long long n;

vector<long long> sa, ssa, sssa;

void builda(vector<long long>& a)
{
	sa.resize(n);
	sa[0] = a[0];
	for (long long i = 1; i < n; ++i)
		sa[i] = (sa[i - 1] + a[i]) % p;
	ssa.resize(n);
	ssa[0] = a[0] * 1;
	for (long long i = 1; i < n; ++i)
		ssa[i] = (ssa[i - 1] + a[i] * (i + 1) % p) % p;
	sssa.resize(n);
	sssa[0] = a[0] * 1;
	for (long long i = 1; i < n; ++i)
		sssa[i] = (sssa[i - 1] + a[i] * (i + 1) % p * (i + 1) % p) % p;
}

long long getsa(long long l, long long r)
{
	if (l == 0) return sa[r];
	return sa[r] - sa[l - 1];
}

long long getssa(long long l, long long r)
{
	if (l == 0) return ssa[r];
	return ((ssa[r] - ssa[l - 1] - l * getsa(l, r) % p) % p + p) % p;
}

long long getsssa(long long l, long long r)
{
	if (l == 0) return sssa[r];
	return ((sssa[r] - sssa[l - 1] - l * 2 * getssa(l, r) % p - l * l % p * getsa(l, r) % p) % p + p) % p;
}

long long geta(long long l, long long r)
{
	return (getsssa(l, r) + getssa(l, r)) * div2 % p;
}


vector<long long> sb, ssb, sssb;

void buildb(vector<long long>& b)
{
	sb.resize(n);
	sb[0] = b[0];
	for (long long i = 1; i < n; ++i)
		sb[i] = (sb[i - 1] + b[i]) % p;
	ssb.resize(n);
	ssb[0] = b[0] * 1;
	for (long long i = 1; i < n; ++i)
		ssb[i] = (ssb[i - 1] + b[i] * (i + 1) % p) % p;
	sssb.resize(n);
	sssb[0] = b[0] * 1;
	for (long long i = 1; i < n; ++i)
		sssb[i] = (sssb[i - 1] + b[i] * (i + 1) % p * (i + 1) % p) % p;
}

long long getsb(long long l, long long r)
{
	if (l == 0) return sb[r];
	return sb[r] - sb[l - 1];
}

long long getssb(long long l, long long r)
{
	if (l == 0) return ssb[r];
	return ((ssb[r] - ssb[l - 1] - l * getsb(l, r) % p) % p + p) % p;
}

long long getsssb(long long l, long long r)
{
	if (l == 0) return sssb[r];
	return ((sssb[r] - sssb[l - 1] - l * 2 * getssb(l, r) % p - l * l % p * getsb(l, r) % p) % p + p) % p;
}

long long getb(long long l, long long r)
{
	return (getsssb(l, r) + getssb(l, r)) * div2 % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long h; cin >> h; n = h;
	vector<long long> a(n);
	for (auto& i : a)
	{
		cin >> h; i = h; i %= p;
	}

	builda(a);
	reverse(a.begin(), a.end());
	buildb(a);

	long long k; cin >> k;

	while (k--)
	{
		long long l, r; cin >> l >> r; --l; --r; long long m = (l + r) / 2;
		cout << (long long)((geta(l, m) + getb(n - r - 1, n - (m + 1) - 1)) % p) << '\n';
	}

	return 0;
}