#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime, d, cnt;

void sieve(int n)
{
	d.resize(n, -1);
	cnt.resize(n);
	d[0] = d[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		cnt[i] = cnt[i - 1];
		if (d[i] == -1)
		{
			d[i] = i;
			prime.push_back(i);
			++cnt[i];
		}
		for (auto& p : prime)
		{
			if (p > d[i]) break;
			if (p * i >= n) break;
			d[p * i] = p;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m = (int)3e6 + 1;
	sieve(m);

	long long n; cin >> n;
	int res = 0;
	for (auto& i : prime)
	{
		if (i * 1ll * i > n) break;
		int c = 0;
		while (!(n % i))
		{
			n /= i;
			c ^= 1;
		}
		if (c)
			res ^= cnt[i];
	}
	if (n > 1)
	{
		if (n < m)
			res ^= cnt[n];
		else
			res = 1;
	}
	
	cout << (res ? "David" : "Vasya") << '\n';

	return 0;
}