#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n, l; cin >> n >> l;
		vector<int> cnt(l);
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			for (int j = 0; j < l; ++j)
			{
				cnt[j] += (x % 2 ? 1 : -1);
				x /= 2;
			}
		}

		int res = 0;
		for (int i = 0; i < l; ++i)
			if (cnt[i] > 0)
				res += (1 << i);

		cout << res << '\n';
	}

	return 0;
}