#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long p = 998244353;
vector<long long> fact(2 * 1e5 + 1);

pair<long long, long long> gGCD(long long a, long long b)
{
	if (a == 0) return { 0, 1 };
	if (b < a)
	{
		auto res = gGCD(b, a); swap(res.first, res.second);
		return res;
	}
	auto res = gGCD(b - a, a);
	return { res.first, res.second - res.first };
}

long long obr(long long x)
{
	return gGCD(x, p).first;
}

long long var(long long k)
{
	return (k * (k - 1) / 2) % p;
}

long long cnk(int n, int k)
{
	return ((fact[n] * obr(fact[k])) % p * obr(fact[n - k])) % p;
}

long long res(long long mx, long long tn, long long need)
{
	mx = max(mx, tn);
	for (int i = mx; i >= 0; ++i)
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, k; cin >> n >> k;
	fact[0] = 1;
	for (int i = 1; i <= 2 * 1e5; ++i)
		fact[i] = (fact[i - 1] * i) % p;
	if (k = 0)
	{
		cout << fact[n] << '\n';
	}
	else
	{

	}

	return 0;
}