#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int k = 73680;

long long sg(long long n)
{
	return n;
}

long long sfg(long long n)
{
	return n * (n + 1) / 2;
}

unordered_map<long long, long long> sfmem;

long long sf(long long n)
{
	auto it = sfmem.find(n);
	if (it != sfmem.end())
		return it->second;

	long long res = sfg(n);
	for (long long l = 2, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		res -= sf(n / l) * (sg(r) - sg(l - 1));
	}
	res /= sg(1); // == g(1)

	return sfmem[n] = res;
}

vector<int> prime, mind, phi;

void sieve(int n)
{
	mind.resize(n + 1);
	phi.resize(n + 1);
	mind[0] = mind[1] = 1;
	phi[0] = 0; phi[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!mind[i])
		{
			prime.push_back(i);
			mind[i] = i;
			phi[i] = i - 1;
		}
		for (auto& j : prime)
		{
			if (j * i > n) break;
			mind[j * i] = j;
			if (j == mind[i])
			{
				phi[j * i] = j * phi[i];
				break;
			}
			phi[j * i] = (j - 1) * phi[i];
		}
	}
}

void precountsf()
{
	sieve(k);
	long long res = 0;
	for (int i = 1; i <= k; ++i)
	{
		res += phi[i];
		sfmem[i] = res;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
		
	precountsf();
	sf(n);
	long long res = 0;
	for (long long l = 1, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		res += (n / l) * (n / l) * (sf(r) - sf(l - 1));
	}
	cout << res << '\n';

	return 0;
}