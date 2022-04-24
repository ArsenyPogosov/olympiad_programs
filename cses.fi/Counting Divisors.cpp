#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime, mdiv;

void erat(int n)
{
	mdiv.resize(n + 1); mdiv[0] = mdiv[1] = 1;
	prime.reserve(int(n / (log(n) + 1)));
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

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	erat(1e6);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		int res = 1;
		while (h > 1)
		{
			int count = 0, tp = mdiv[h];
			while (h % tp == 0)
			{
				++count;
				h /= tp;
			}
			res *= count + 1;
		}
		cout << res << '\n';
	}

	return 0;
}