#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime, mdiv;

void erat(int n)
{
	prime.reserve(int(n / log(n)) + 10);
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
	erat(1000000);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long h; cin >> h;
		int p = Sqrt(h);
		if (p != -1 && mdiv[p] == p)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}