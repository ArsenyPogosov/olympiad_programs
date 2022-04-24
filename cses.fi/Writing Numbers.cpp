#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> tenp(19, 1);

long long count(long long x, int s)
{
	long long res = 0, len;
	for (len = 0; len + 1 < 19 && tenp[len + 1] <= x; ++len);
	for (int i = 0; i <= len; ++i)
	{
		res += max((x / tenp[i + 1] - (s == 0)), 0ll) * tenp[i];
		if (!(s == 0 && x / tenp[i + 1] == 0))
		{
			if ((x / tenp[i]) % 10 > s)
				res += tenp[i];
			else if ((x / tenp[i]) % 10 == s)
				res += (x % tenp[i] + 1);
		}
	}
	return res;
}

bool check(long long x)
{
	return (count(x, 1) <= n) && (count(x, 0) <= n);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < 19; ++i) tenp[i] = tenp[i - 1] * 10;
	cin >> n;
	long long l = 1, r = 1e18;
	while (l + 1 < r)
	{
		long long m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	cout << l << '\n';

	return 0;
}