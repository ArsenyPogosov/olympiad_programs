#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> bad(n);

	for (int i = 0; i < k; ++i)
	{
		int m; cin >> m;
		for (int j = 0; j < m; ++j)
		{
			int h; cin >> h; 
			bad[h - 1] |= 1 << i;
		}
	}

	map<int, int> cnt;
	for (auto& i : bad)
		++cnt[i];
	if (k > 40 || ((1ll << k) > cnt.size()))
	{
		int res;
		for (int i = 0; i < (1 << k); ++i)
			if (cnt[i] == 0)
			{
				res = i;
				break;
			}
		for (int i = 0; i < k; ++i)
		{
			cout << res % 2; res /= 2;
		}
	}
	else
	{
		int res; int bres = 1e9;
		for (int i = 0; i < (1 << k); ++i)
			if (cnt[i] < bres)
			{
				res = i;
				bres = cnt[i];
			}
		for (int i = 0; i < k; ++i)
		{
			cout << res % 2; res /= 2;
		}
	}
	cout << '\n';

	return 0;
}