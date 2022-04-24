#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x, an, bn; cin >> n >> x; an = n / 2; bn = (n + 1) / 2;
	vector<int> a(an), b(bn);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	map<int, int> m;
	vector<int> mask1sum((1 << an)), mask2sum((1 << bn)); mask1sum[0] = mask2sum[0] = 0;
	for (int mask = 0; mask < (1 << an); ++mask)
	{
		for (int i = 0; i < an; ++i)
			if (mask & (1 << i))
			{
				if (mask1sum[mask ^ (1 << i)] == -1)
					mask1sum[mask] = -1;
				else
					mask1sum[mask] = mask1sum[mask ^ (1 << i)] + a[i];
				if (mask1sum[mask] > x)
					mask1sum[mask] = -1;
				break;
			}
		++m[mask1sum[mask]];
	}
	long long res = 0;
	for (int mask = 0; mask < (1 << bn); ++mask)
	{
		for (int i = 0; i < bn; ++i)
			if (mask & (1 << i))
			{
				if (mask2sum[mask ^ (1 << i)] == -1)
					mask2sum[mask] = -1;
				else
					mask2sum[mask] = mask2sum[mask ^ (1 << i)] + b[i];
				if (mask2sum[mask] > x)
					mask2sum[mask] = -1;
				break;
			}
		if (mask2sum[mask] != -1)
		{
			auto it = m.find(x - mask2sum[mask]);
			if (it != m.end())
				res += it->second;
		}
	}
	cout << res << '\n';

	return 0;
}