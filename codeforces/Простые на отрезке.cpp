#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime, mdiv;

void erat(int n)
{
	prime.reserve(int(n / max(1.0, log(n))) + 10);
	mdiv.resize(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		if (!mdiv[i])
		{
			mdiv[i] = i;
			prime.push_back(i);
		}
		for (auto& p : prime)
		{
			if (i * p > n || p > mdiv[i]) break;
			mdiv[i * p] = p;
		}
	}
}

int Sqrt(long long h)
{
	int res = int(sqrt(h));
	for (int i = max(0, res - 2); i <= res + 2; ++i)
		if ((long long)(i)*i == h)
			return i;
	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, k; cin >> a >> b >> k;
	erat(b);
	vector<int> tok(b + 1, 1e9);
	int it = 0;
	for (int i = 0; i < int(prime.size()) - k + 1; ++i)
	{
		for (; it <= prime[i]; ++it)
			tok[it] = prime[i + k - 1] - it + 1;
	}
	int l = 1, bestl = 1e9;
	for (int i = a; i <= b - l + 1; ++i)
	{
		l = max(l, tok[i]);
		if (l <= b - i + 1)
			bestl = min(bestl, b - i + 1);
		else
			break;
	}
	if (bestl == 1e9)
		cout << -1 << '\n';
	else
		cout << bestl << '\n';

	return 0;
}