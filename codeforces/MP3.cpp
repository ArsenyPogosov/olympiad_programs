#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int k = 1 << min((8 * m) / n, 30);
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());
	int best = 0, l = 0, r = 1, count = 1;
	for (; l < n; ++l, --count)
	{
		if (l >= r || (l > 0 && a[l - 1] == a[l])) ++count;
		r = max(r, l + 1);
		for (; r < n; ++r)
		{
			if (a[r] == a[r - 1]) continue;
			if (count == k) break;
			++count;
		}
		best = max(best, r - l);
	}
	cout << n - best << '\n';

	return 0;
}