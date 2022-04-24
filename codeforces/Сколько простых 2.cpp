#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int cnt = 0;
vector<bool> prime;

void sieve(int n)
{
	prime.resize(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= n; ++i)
		if (prime[i])
			for (int j = i * i; j <= n; j += i)
				prime[j] = false;
	cnt = accumulate(prime.begin(), prime.end(), 0);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	sieve(n);
	cout << cnt << '\n';

	return 0;
}