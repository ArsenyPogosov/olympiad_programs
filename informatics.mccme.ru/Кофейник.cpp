#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	if (k > n)
	{
		while (n--)
			cin >> k;
		cout << 0 << '\n';

		return 0;
	}

	vector<int> used(k);
	int t = 1, cnt = k, res = 0;
	while (n--)
	{
		int h; cin >> h; --h;

		cnt -= (used[h] != t);
		used[h] = t;

		if (!cnt)
		{
			++res;
			cnt = k - 1;
			used[h] = ++t;
		}
	}
	cout << res << '\n';

	return 0;
}