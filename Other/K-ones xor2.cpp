#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	if (k == 0)
	{
		cout << "0\n";
		return 0;
	}
	long long best = 0;
	int hbest = 0;
	for (int i = 0; i < m; ++i)
	{
		vector<pair<long long, int>> c(i);
		for (int j = 0; j < i; ++j) c[j] = { 0, j };
		long long tek = 0;
		int htek = (1 << i);
		for (auto&j: a)
			if ((j & (1 << i)) == 0)
			{
				tek += (1 << i);
				for (int k = 0; k < i; ++k)
					if ((j & (1 << k)) == 0)
						c[k].first -= (1 << k);
					else
						c[k].first += (1 << k);
			}
		sort(c.begin(), c.end());
		for (int j = 0; j < min(i, k - 1); ++j)
		{
			if (c[j].first >= 0) break;
			tek += -c[j].first;
			htek += (1 << (c[j].second));
		}
		if (tek > best)
		{
			best = tek;
			hbest = htek;
		}
	}
	cout << hbest << '\n';

	return 0;
}