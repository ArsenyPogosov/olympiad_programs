#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long N = 100;
const long long NPRIME = 541;

vector<long long> prime, mind;
void sieve(long long n = NPRIME)
{
	mind.resize(n + 1);
	for (long long i = 2; i <= n; ++i)
	{
		if (!mind[i])
		{
			mind[i] = i;
			prime.push_back(i);
		}

		for (auto& p: prime)
		{
			if (p > mind[i] || p * i > n) break;
			mind[p * i] = p;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	sieve();

	long long q; cin >> q;
	while (q--)
	{
		long long n; cin >> n;
		vector<long long> e(n);
		for (auto& i : e) cin >> i;

		long long l = 0, r = 1;
		for (long long i = 0; i < n; ++i)
			r = max(r, prime[i] * 1ll * e[i]);

		while (l + 1 < r)
		{
			long long m = (l + r) / 2;

			bool good = true;
			for (long long i = 0; good && i < n; ++i)
			{
				long long res = 0;
				long long mm = m / prime[i];
				while (res < e[i] && mm > 0)
				{
					res += mm;
					mm /= prime[i];
				}

				if (res < e[i])
					good = false;
			}

			if (good)
				r = m;
			else
				l = m;
		}

		cout << r << '\n';
	}

	return 0;
}