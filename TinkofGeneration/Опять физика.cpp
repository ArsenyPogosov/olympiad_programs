#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

long long GCD(long long a, long long b)
{
	return (a ? GCD(b % a, a) : b);
}

pair<string, string> norm(long long a, long long b, long long c)
{
	long long d = GCD(a, b); a /= d; b /= d;
	long long d2 = GCD(d, c); c /= d2; d /= d2;

	if (a < 0)
	{
		a = -a; b = -b; c = -c;
	}
	if (a == 0 && b < 0)
	{
		a = -a; b = -b; c = -c;
	}

	return { to_string(a) + ';' + to_string(b) , to_string(c) + '/' + to_string(d) };
}

long long sum;
unordered_map<string, pair<long long, unordered_map<string, long long>>> store;

void add(long long a, long long b, long long c, long long q)
{
	sum += q;

	auto res = norm(a, b, c);
	store[res.first].first += q;
	store[res.first].second[res.second] += q;
}

long long ans(long long a, long long b, long long c)
{
	auto res = norm(a, b, c);
	long long qall = store[res.first].second[res.second];
	if (qall > 0) return INF;
	if (qall < 0) return -INF;

	return sum - store[res.first].first;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	while (n--)
	{
		long long h, a, b, c; cin >> h >> a >> b >> c;
		if (h == 1)
		{
			long long q; cin >> q;
			add(a, b, c, q);
		}
		if (h == 2)
		{
			long long res = ans(a, b, c);
			cout << (abs(res) < INF ? to_string(res) : "inf") << '\n';
		}
	}

	return 0;
}