#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p;

int qpow(int x, int k)
{
	int res = 1, tek = x;
	for (int i = 1; i <= k; i <<= 1, tek = tek * 1ll * tek % p)
		if (k & i)
			res = res * 1ll * tek % p;

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> p;
	int phi = p - 1, h = p - 1;
	vector<int> tocheck;
	for (int i = 2; i * i <= h; ++i)
		if (!(h % i))
		{
			tocheck.push_back(phi / i);
			while (!(h % i)) h /= i;
		}
	if (h > 1)
		tocheck.push_back(phi / h);

	for (int i = 1; i < p; ++i)
	{
		bool good = true;
		for (auto& j : tocheck)
			if (qpow(i, j) == 1)
			{
				good = false;
				break;
			}
		if (good)
		{
			cout << i << '\n';
			break;
		}
	}

	return 0;
}