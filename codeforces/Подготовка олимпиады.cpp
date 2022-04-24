#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, l, r, x; cin >> n >> l >> r >> x;
	vector<int> mass(n);
	for (auto& i : mass) cin >> i;
	int count = 0;
	for (int mask = 1; mask < (1 << n); ++mask)
	{
		long long sum = 0;
		int mn = 1e9, mx = -1;
		for (int wmask = mask, i = 0; wmask > 0; wmask /= 2, ++i)
			if (wmask % 2)
			{
				mn = min(mn, mass[i]);
				mx = max(mx, mass[i]);
				sum += mass[i];
			}
		if (l <= sum && sum <= r && (mx - mn >= x)) ++count;
	}
	cout << count << '\n';

	return 0;
}