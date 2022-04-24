#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime, mdiv;

void erat(int n)
{
	mdiv.resize(n + 1); mdiv[0] = mdiv[1] = 1;
	prime.reserve(n / (log(n) + 1));
	for (int i = 2; i <= n; ++i)
	{
		if (!mdiv[i])
		{
			mdiv[i] = i;
			prime.push_back(i);
		}
		for (auto& p : prime)
		{
			if (i * 1ll * p > n || p > mdiv[i]) break;
			mdiv[i * p] = p;
		}
	}
}

int start;
vector<int> res;
void add(int n)
{
	if (n == 1) return;

	int p = mdiv[n], alp = 0;
	while (n % p == 0) ++alp, n /= p;
	add(n);
	int end = res.size();
	for (int j = 1, pow = p; j <= alp; ++j, pow *= p)
		for (int i = start; i < end; ++i)
			res.push_back(res[i] * pow);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	erat(1e6);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		start = res.size();
		res.push_back(1);
		add(h);
	}
	sort(res.rbegin(), res.rend());
	for (int i = 0; i < res.size(); ++i)
		if (res[i] == res[i + 1])
		{
			cout << res[i] << '\n';
			return 0;
		}

	return 0;
}