#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime;
vector<int> mdiv;

void erat(int n)
{
	prime.reserve(int(log2(n)) * 5);
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

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	erat(n);
	if (k == 0)
	{
		cout << "YES\n";
		return 0;
	}
	if (prime.size() < 3)
	{
		cout << "NO\n";
		return 0;
	}
	int count = 0, tit = 0;
	for (int i = 2; i < prime.size() && count < k; ++i)
	{
		while (tit + 2 < prime.size() && prime[tit + 1] + prime[tit + 2] + 1 <= prime[i])
			++tit;
		if (prime[tit] + prime[tit + 1] + 1 == prime[i])
			++count;
	}
	if (count >= k)
	{
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";

	return 0;
}