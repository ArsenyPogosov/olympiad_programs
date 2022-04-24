#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());
	vector<long long> ls(n), rs(n);
	partial_sum(a.begin(), a.end(), ls.begin());
	partial_sum(a.rbegin(), a.rend(), rs.begin());
	long long res = min(rs[n - 2] - a[0] * (n - 1), a[n - 1] * (n - 1) - ls[n - 2]);
	for (int i = 1; i < n - 1; ++i)
		res = min(res, (a[i] * i - ls[i - 1]) + (rs[n - i - 2] - a[i] * (n - i - 1)));
	cout << res;

	return 0;
}