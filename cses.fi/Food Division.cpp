#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> d(n);
	for (auto& i : d) cin >> i;
	for (auto& i : d)
	{
		int h; cin >> h; i -= h;
	}
	partial_sum(d.begin(), d.end() - 1, d.begin());
	d[n - 1] = 0;
	sort(d.begin(), d.end());
	long long sum = accumulate(d.begin(), d.end(), 0ll), tek = 0, res = 1e18;
	for (int i = 0; i < n; ++i)
	{
		res = min(res, (d[i] * i - tek) + ((sum - tek) - d[i] * (n - i)));
		tek += d[i];
	}
	cout << res << '\n';

	return 0;
}