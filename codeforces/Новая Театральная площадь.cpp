#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, m, x, y; cin >> n >> m >> x >> y; y = min(y, x * 2);
		long long res = 0;
		for (int i = 0; i < n; ++i)
		{
			vector<char> tek(m);
			for (auto& j : tek) cin >> j;
			int k = 0;
			while (k < m)
			{
				if (tek[k] == '*')
				{
					++k;
					continue;
				}
				if (k < m - 1 && tek[k + 1] == '.')
				{
					k += 2; res += y;
				}
				else
				{
					++k; res += x;
				}
			}
		}
		cout << res << '\n';
	}

	return 0;
}