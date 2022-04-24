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

int countk(int a, int b, int k)
{
	if (b <= 5 * 1e6)
	{
		int res = 0;
		for (int i = a; i <= b; ++i)
			if (mdiv[i] == prime[k]) ++res;
		return res;
	}
	if (a > b) return 0;
	int l = (a + prime[k] - 1) / prime[k], r = b / prime[k];
	int res = r - l + 1;
	for (int i = 0; i < k; ++i) res -= countk(l, r, i);
	return res;
}

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	erat(5 * 1e6);
	int a, b, k; cin >> a >> b >> k;
	if (k > 5 * 10000)
	{
		if (k < a || b < k) {
			cout << 0 << '\n'; return 0;
		}
		bool prime = true;
		for (int i = 2; i * i <= k && prime; ++i) prime = k % i;
		if (prime)
		{
			cout << 1 << '\n'; return 0;
		}
		cout << 0 << '\n'; return 0;
	}
	int it = find(prime.begin(), prime.end(), k) - prime.begin();
	if (it >= prime.size())
	{
		cout << 0 << '\n'; return 0;
	}
	cout << countk(a, b, it) << '\n';

	return 0;
}